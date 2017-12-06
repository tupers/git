#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

typedef struct
{
	short graph = -1;
	short present = -1;
}_QueueFamilyIndex;

typedef struct
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
}_SwapChainSupportInfo;

class coreFramework {
public:
	coreFramework();
	~coreFramework();
	void init();
	void exec();
private:
	void initWindow();
	void initVulkan();

	void createInstance();
	void createLogicalDevice();
	void createSurface();
	void createSwapChain();
	void createImageViews();
	void createRenderPass();
	void createGraphicsPipeline();
	VkShaderModule  createShaderModule(const std::vector<char>& code);
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	void setupDebugCallback();
	VkResult CreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
	void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
	bool isDeviceSuitable(VkPhysicalDevice device);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	_SwapChainSupportInfo querySwapChainSupport(VkPhysicalDevice device);
	void pickPhysicalDevice();
	_QueueFamilyIndex findQueueFamilies(VkPhysicalDevice device);

	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

	GLFWwindow* m_hWindow;

	VkDebugReportCallbackEXT m_callback;
	VkInstance vkInst;
	VkDevice vkDevice;
	VkQueue vkGraphicsQueue;
	VkQueue vkPresentQueue;
	VkSurfaceKHR vkSurface;
	VkSwapchainKHR vkSwapChain;
	VkRenderPass vkRenderPass;
	VkPipelineLayout vkPipelineLayout;
	VkPipeline vkGraphicsPipeline;
	std::vector<VkImage> m_vecSwapChainImages;
	std::vector<VkImageView>m_vecSwapChainImageViews;
	VkFormat m_tSwapChainImageFormat;
	VkExtent2D m_tSwapChainExtent;
	VkPhysicalDevice vkPhysicalDevice = VK_NULL_HANDLE;


	const std::vector<const char*> m_vecValidationLayers = {
		"VK_LAYER_LUNARG_standard_validation"
	};

	const std::vector<const char*> m_vecDeviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
};