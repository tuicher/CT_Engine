#ifndef CTE_SWAPCHAIN_H
#define CTE_SWAPCHAIN_H

#include "CTE_Device.h"
#include "CTE_Window.h"

#include <string>
#include <vector>

namespace CTE
{
	class CTE_SwapChain
	{
	public:
		static constexpr int MAX_FRAMES_IN_FLIGHT = 2;

		CTE_SwapChain(CTE_Window& window, CTE_Device& device) : _window(window), _device(device) { init(); };
		~CTE_SwapChain() { cleanupSwapChain(); cleanupSyncObjects(); }

		CTE_SwapChain(const CTE_SwapChain&) = delete;
		void operator = (const CTE_SwapChain&) = delete;

		inline VkFramebuffer getFrameBuffer(int index) { return swapChainFramebuffers[index]; }
		inline VkRenderPass getRenderPass() { return renderPass; }
		inline VkImageView getImageView(int index) { return swapChainImageViews[index]; }
		void recreateSwapChain();
		void cleanupSwapChain();
		inline size_t imageCount() { return swapChainImages.size(); }
		inline VkFormat getSwapChainImageFormat() { return swapChainImageFormat; }
		inline VkExtent2D getSwapChainExtent() { return swapChainExtent; }
		inline uint32_t width() { return swapChainExtent.width; }
		inline uint32_t height() { return swapChainExtent.height; }
		inline float extentAspectRatio() { return static_cast<float>(swapChainExtent.width) / static_cast<float>(swapChainExtent.height); }

		VkFormat findDepthFormat();
		VkResult acquireNextImage(uint32_t *imageIndex);
		VkResult submitCommandBuffers(const VkCommandBuffer *buffers, uint32_t *imageIndex);

	private:
		void init();
		void cleanupSyncObjects();
		void createSwapChain();
		void createImageViews();
		void createDepthResources();
		void createRenderPass();
		void createFramebuffers();
		void createSyncObjects();

		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;

		std::vector<VkFramebuffer> swapChainFramebuffers;
		VkRenderPass renderPass;

		std::vector<VkImage> depthImages;
		std::vector<VkDeviceMemory> depthImageMemorys;
		std::vector<VkImageView> depthImageViews;
		std::vector<VkImage> swapChainImages;
		std::vector<VkImageView> swapChainImageViews;

		CTE_Window &_window;
		CTE_Device &_device;

		VkSwapchainKHR swapChain;

		std::vector<VkSemaphore> imageAvailableSemaphores;
		std::vector<VkSemaphore> renderFinishedSemaphores;
		std::vector<VkFence> inFlightFences;
		std::vector<VkFence> imagesInFlight;
		size_t currentFrame = 0;
	};
}

#endif
