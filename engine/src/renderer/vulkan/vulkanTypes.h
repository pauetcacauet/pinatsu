#pragma once

#include "vulkan\vulkan.h"
#include "core\assert.h"
#include "core\logger.h"
#include "math_types.h"
#include <external\glm\glm.hpp>
#include <external\glm\gtc\matrix_transform.hpp>
#include <vector>

#define VK_CHECK(x) { PASSERT(x == VK_SUCCESS); }

typedef struct VulkanDevice
{ 
    VkPhysicalDevice    physicalDevice;
    VkDevice            handle;

    u32 graphicsQueueIndex;
    u32 presentQueueIndex;
    u32 transferQueueIndex;
    u32 computeQueueIndex;

    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkQueue computeQueue;
    VkQueue transferQueue;

    VkPhysicalDeviceProperties properties;
    VkPhysicalDeviceFeatures features;
    VkPhysicalDeviceMemoryProperties memory;

    VkCommandPool commandPool;
    VkCommandPool transferCmdPool;

} VulkanDevice;

typedef struct VulkanSwapchainSupport
{
    VkSurfaceCapabilitiesKHR capabilities;
    u32 formatCount;
    VkSurfaceFormatKHR* formats;
    u32 presentModeCount;
    VkPresentModeKHR* presentModes;
} VulkanSwapchainSupport;

typedef struct VulkanRenderpass
{
    VkRenderPass handle;
} VulkanRenderpass;

typedef struct Framebuffer
{
    VkFramebuffer handle;
    std::vector<VkImageView> attachments;
    VulkanRenderpass* renderpass;
} Framebuffer;

typedef struct VulkanSwapchain
{
    VkSwapchainKHR      handle;
    VkSurfaceFormatKHR  format;
    VkPresentModeKHR    presentMode;
    VkExtent2D          extent;
    u32                 imageCount; // Number of images in the swapchain.
    u32                 maxImageInFlight; // Number of images in flight.

    std::vector<VkImage>        images;
    std::vector<VkImageView>    imageViews;
    std::vector<Framebuffer>    framebuffers;
} VulkanSwapchain;

typedef struct CommandBuffer
{
    VkCommandBuffer handle;
} CommandBuffer;

typedef struct Pipeline
{
    VkPipelineLayout layout;
    VkPipeline pipeline;
} Pipeline;

typedef struct ShaderObject
{
    VkShaderModule shaderModule;
} ShaderObject;

typedef struct VulkanFence
{
    VkFence handle;
    bool signaled;
} VulkanFance;

typedef struct Vertex
{
    vec3 position;
    vec4 color;
}Vertex;

typedef struct MVPBuffer
{
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
} MVPBuffer;

// TODO make configurable
#define VULKAN_MAX_MESHES 10

typedef struct VulkanMesh
{
    u32 id;
    u32 vertexCount;
    u32 vertexSize;
    u32 vertexOffset;
    u32 indexCount;
    u32 indexOffset;
} VulkanMesh;

typedef struct VulkanState
{
    VkInstance      instance;
    VulkanDevice    device;

    VkDebugUtilsMessengerEXT debugMessenger;

    VkSurfaceKHR    surface;

    u32 imageIndex; // Index to the swapchain image to paint.
    u32 currentFrame; // The actual index frame.

    // TODO implement own allocator for vulkan
    // VkAllocationCallbacks* allocator;

    // TODO Temporal variables
    VkBuffer dataBuffer;
    VkDeviceMemory memory;
    MVPBuffer ubo{};

    VulkanMesh* vulkanMeshes;

    // TODO All this should go to a pass struct
    VkDescriptorPool descriptorPool;
    VkDescriptorSetLayout descriptorLayout;
    std::vector<VkDescriptorSet> descriptorSet;

    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;

    VulkanSwapchainSupport swapchainSupport{};
    VulkanSwapchain swapchain;
    bool recreatingSwapchain;

    u32 clientWidth;
    u32 clientHeight;
    bool resized;

    VulkanRenderpass renderpass;

    std::vector<CommandBuffer> commandBuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VulkanFence> frameInFlightFences;

    ShaderObject vertexShaderObject;
    ShaderObject fragmentShaderObject;

    Pipeline graphicsPipeline;
} VulkanState;