#include "CTE_FileManager.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace CTE
{
	CTE_FileManager::CTE_FileManager(const std::string& vertexShaderPath, const std::string& fragmenShaderPath)
	{
		createGraphicsPipeline(vertexShaderPath, fragmenShaderPath);
	}

	std::vector<char> CTE_FileManager::readFile(const std::string& fileName)
	{
		std::ifstream file{ fileName, std::ios::ate | std::ios::binary };

		if (!file.is_open()) 
		{
			throw std::runtime_error("failed to open file: " + fileName);
		}

		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}

	void CTE_FileManager::createGraphicsPipeline(const std::string& vertexShaderPath, const std::string& fragmenShaderPath)
	{
		std::vector<char> vertShader = readFile(vertexShaderPath);
		std::vector<char> fragShader = readFile(fragmenShaderPath);

		std::cout << "Vertex Shader size: " << vertShader.size() << std::endl;
		std::cout << "Fragment Shader size: " << fragShader.size() << std::endl;
	}
}