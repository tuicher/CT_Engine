#ifndef CTENG_H
#define CTENG_H

#include "CTE_Pipeline.h"
#include "CTE_SwapChain.h"
#include "CTE_Window.h"

#include <memory>
#include <vector>


namespace CTE
{
	class CTEngine
	{
	public:
		static constexpr int HEIGHT = 600;
		static constexpr int WIDTH = 800;

		CTEngine();
		~CTEngine();

		CTEngine(const CTEngine&) = delete;
		void operator=(const CTEngine&) = delete;

		void run();

	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();


		CTE_Window cteWindow{ WIDTH, HEIGHT};
		CTE_Device cteDevice{ cteWindow };
		CTE_SwapChain cteSwapChain{ cteWindow, cteDevice };
		VkPipelineLayout pipelineLayout;
		std::unique_ptr<CTE_Pipeline> simplePipeline;
		std::vector<VkCommandBuffer> commandBuffers;
	};
}

#endif // CTENG_H