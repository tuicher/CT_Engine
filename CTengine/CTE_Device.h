#pragma once

#include "CTE_Window.h"

#include<string>
#include<vector>

namespace CTE
{
	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	struct QueueFamilyIndices
	{
		uint32_t graphicsFamily;
		uint32_t presentFamily;
		bool graphicsFamilyHasValue = false;
		bool presentFamilyHasValue = false;
		inline bool isComplete() { return graphicsFamilyHasValue && presentFamilyHasValue; }
	};

	class CTE_Device
	{
		public:
		#ifdef NDEBUG
			const bool enableValidationLayers = false;
		#else
			const bool enableValidationLayers = true;
		#endif // NDEBUG

			CTE_Device(CTE_Window &window);
			~CTE_Device();

			CTE_Device(const CTE_Device &) = delete;
			void operator=(const CTE_Device &) = delete;
			CTE_Device(CTE_Device &&) = delete;
			CTE_Device &operator=(CTE_Device&&) = delete;

			inline VkCommandPool getCommandPool() { return commandPool; }
			inline VkDevice device() { return _device; }
			inline VkSurfaceKHR surface() { return _surface; }
			inline VkQueue graphicsQueue() { return _graphicsQueue; }
			inline VkQueue presentQueue() { return _presentQueue; }

			inline SwapChainSupportDetails getSwapChainSupport() { return querySwapChainSupport(physicalDevice); }
			inline QueueFamilyIndices findPhysicalQueueFamilies() { return findQueueFamilies(physicalDevice); }
			uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
			VkFormat findSupportedFormat(
				const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);


			void createBuffer(
				VkDeviceSize size,
				VkBufferUsageFlags usage,
				VkMemoryPropertyFlags properties,
				VkBuffer& buffer,
				VkDeviceMemory& bufferMemory);
			VkCommandBuffer beginSingleTimeCommands();
			void endSingleTimeCommands(VkCommandBuffer commandBuffer);
			void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
			void copyBufferToImage(
				VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layerCount);

			void createImageWithInfo(
				const VkImageCreateInfo& imageInfo,
				VkMemoryPropertyFlags properties,
				VkImage& image,
				VkDeviceMemory& imageMemory);

			VkPhysicalDeviceProperties properties;

		private:

			void createInstance();
			void setupDebugMessenger();
			inline void createSurface() { window.createWindowSurface(instance, &_surface); }
			void pickPhysicalDevice();
			void createLogicalDevice();
			void createCommandPool();

			bool isDeviceSuitable(VkPhysicalDevice device);
			std::vector<const char *> getRequiredExtensions();
			bool checkValidationLayerSupport();
			QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
			void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
			void hasGflwRequiredInstanceExtensions();
			bool checkDeviceExtensionSupport(VkPhysicalDevice device);
			SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

			VkInstance instance;
			VkDebugUtilsMessengerEXT debugMessenger;
			VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
			CTE_Window& window;
			VkCommandPool commandPool;

			VkDevice _device;
			VkSurfaceKHR _surface;
			VkQueue _graphicsQueue;
			VkQueue _presentQueue;

			const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
			const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
	};
}
