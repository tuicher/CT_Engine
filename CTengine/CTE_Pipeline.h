#ifndef CTE_Pipeline_H
#define CTE_Pipeline_H

#include "CTE_Device.h"

#include <string>
#include <vector>

namespace CTE
{

	struct PipelineConfigInfo 
	{
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};

	class CTE_Pipeline
	{
	public:
		CTE_Pipeline(
			CTE_Device& device,
			const std::string& vertexShaderPath,
			const std::string& fragmenShaderPath,
			const PipelineConfigInfo& configInfo);
		~CTE_Pipeline();

		CTE_Pipeline(const CTE_Pipeline&) = delete;
		void operator=(const CTE_Pipeline&) = delete;

		inline void bind(VkCommandBuffer command_buffer) { vkCmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, graphicsPipeline); };

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:
		void createGraphicsPipeline(
			const std::string& vertexShaderPath,
			const std::string& fragmenShaderPath,
			const PipelineConfigInfo& configInfo);

		void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);


		CTE_Device& cteDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
	
}

#endif // !CTE_Pipeline.h

