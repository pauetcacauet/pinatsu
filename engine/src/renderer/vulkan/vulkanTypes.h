#pragma once

#include "vulkan\vulkan.h"
#include "core\assert.h"
#include <vector>
#include "core\logger.h"

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

typedef struct VulkanState
{
    VkInstance      instance;
    VulkanDevice    device;

    VkDebugUtilsMessengerEXT debugMessenger;

    VkSurfaceKHR    surface;

    u32 imageIndex; // Index to the swapchain image to paint.
    u32 frameCount; // Number of frames during the application.
    u32 frameIndex;

    // TODO implement own allocator for vulkan
    // VkAllocationCallbacks* allocator;

    u32 clientWidth;
    u32 clientHeight;

    VulkanSwapchainSupport swapchainSupport{};
    VulkanSwapchain swapchain;

    VulkanRenderpass renderpass;

    std::vector<CommandBuffer> commandBuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> frameInFlightFences;

    ShaderObject vertexShaderObject;
    ShaderObject fragmentShaderObject;

    Pipeline graphicsPipeline;

} VulkanState;