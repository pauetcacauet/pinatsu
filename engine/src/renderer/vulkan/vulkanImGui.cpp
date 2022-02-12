#include "vulkanImGui.h"
#include "vulkanTypes.h"
#include "vulkanCommandBuffer.h"

#include "memory/pmemory.h"

// TODO TEMP
//#include "systems/entitySystem.h"
#include "systems/entitySystemComponent.h"

struct imguiState
{
    VkDescriptorPool descriptorPool;
    const VulkanRenderpass* renderPass;
    const VulkanDevice* device;
    const VulkanSwapchain* swapchain;
};

static imguiState* imgui = nullptr;

void
imguiInit(
    VulkanState* state, 
    const VulkanRenderpass* renderpass)
{
    imgui = (imguiState*)memAllocate(sizeof(imguiState), MEMORY_TAG_MANAGER);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    imgui->device = &state->device;
    imgui->renderPass = renderpass;
    imgui->swapchain = &state->swapchain;

    VkDescriptorPoolSize desc{};
    desc.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    desc.descriptorCount = 1;

    VkDescriptorPoolCreateInfo poolInfo{VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO};
    poolInfo.poolSizeCount = 1;
    poolInfo.pPoolSizes = &desc;
    poolInfo.maxSets = 1;

    vkCreateDescriptorPool(imgui->device->handle, &poolInfo, nullptr, &imgui->descriptorPool);

    ImGui_ImplVulkan_InitInfo vkinit = {};
    vkinit.Instance = state->instance;
    vkinit.PhysicalDevice = imgui->device->physicalDevice;
    vkinit.Device = imgui->device->handle;
    vkinit.QueueFamily = imgui->device->graphicsQueueIndex;
    vkinit.Queue = imgui->device->graphicsQueue;
    vkinit.PipelineCache = nullptr;
    vkinit.DescriptorPool = imgui->descriptorPool;
    vkinit.MinImageCount = imgui->swapchain->imageCount;
    vkinit.ImageCount = imgui->swapchain->imageCount;

    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2((f32)state->clientWidth, (f32)state->clientHeight);
    io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

    ImGui_ImplWin32_Init(state->windowHandle);
    if(!ImGui_ImplVulkan_Init(&vkinit, imgui->renderPass->handle)){
        PERROR("Error initializing imgui.");
    }

    VkCommandBuffer cmd;
    vulkanCommandBufferAllocateAndBeginSingleUse(*imgui->device, imgui->device->commandPool, cmd);
    ImGui_ImplVulkan_CreateFontsTexture(cmd);
    vulkanCommandBufferEndSingleUse(*imgui->device, imgui->device->commandPool, imgui->device->graphicsQueue, cmd);
    ImGui_ImplVulkan_DestroyFontUploadObjects();
}

void
imguiRender(
    VkCommandBuffer& cmd,
    const RenderPacket& packet)
{
    ImGui_ImplVulkan_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    //ImGui::ShowDemoWindow();

    EntitySystem* entitySystem = EntitySystem::Get();
    auto& entities = entitySystem->getAvailableEntities();

    for(auto& it = entities.begin(); it != entities.end(); it++)
    {
        if(it->second[entitySystem->getComponentType<RenderComponent>(it->first)] == 1)
        {
            if(ImGui::TreeNode("Mesh"))
            {
                TransformComponent* comp = &entitySystem->getComponent<TransformComponent>(it->first);
                ImGui::DragFloat3(" Position", &comp->position.x, 1.0f);
                ImGui::DragFloat4(" Rotation", &comp->rotation.x, 1.0f);
                ImGui::DragFloat3(" Scale", &comp->scale.x, 1.0f);
                ImGui::TreePop();
            }
        }
        if(it->second[entitySystem->getComponentType<LightPointComponent>(it->first)] == 1)
        {
            if(ImGui::TreeNode("Light"))
            {
                LightPointComponent* comp = &entitySystem->getComponent<LightPointComponent>(it->first);
                ImGui::DragFloat3(" Position ", &comp->position.x, 1.0f);
                ImGui::DragFloat3(" Colour", &comp->color.r, 1.0f);
                ImGui::DragFloat(" Radius", &comp->radius, 1.0f);
                ImGui::TreePop();
            }
        }
    }
    ImGui::Render();
    ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), cmd);
}

void
imguiDestroy()
{
    vkDestroyDescriptorPool(imgui->device->handle, imgui->descriptorPool, nullptr);
    ImGui_ImplVulkan_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}