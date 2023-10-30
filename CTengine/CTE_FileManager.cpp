#include "CTE_FileManager.h"

#include <fstream>
#include <stdexcept>
#include <vector>

namespace CTE
{

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
}