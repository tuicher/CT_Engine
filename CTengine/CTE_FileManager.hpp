#ifndef CTR_FILEMANAGER_H
#define CTR_FILEMANAGER_H

#include <string>
#include <vector>

namespace CTE
{
	class CTE_FileManager
	{
	public:
		CTE_FileManager(const std::string &vertexShaderPath, const std::string& fragmenShaderPath);

	private:
		static std::vector<char> readFile(const std::string& fileName);

		void createGraphicsPipeline(const std::string& vertexShaderPath, const std::string& fragmenShaderPath);
	};
}

#endif // !CTR_FILEMANAGER_H
