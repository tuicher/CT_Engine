#ifndef CTE_FILEMANAGER_H
#define CTE_FILEMANAGER_H

#include <string>
#include <vector>

namespace CTE
{
	class CTE_FileManager
	{
	public:
		static std::vector<char> readFile(const std::string& fileName);
		
	};
}

#endif // !CTE_FILEMANAGER_H
