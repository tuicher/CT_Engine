#ifndef CTENG_H
#define CTENG_H

#include "CTE_FileManager.hpp"
#include "CTE_Window.hpp"

namespace CTE
{
	class CTEngine
	{
	public:
		static constexpr int HEIGHT = 600;
		static constexpr int WIDTH = 800;
		void run();

	private:
		CTE_Window CTEwindow{ WIDTH, HEIGHT};
		CTE_FileManager CTEfilemanager{ "shader/vert.spv", "shader/frag.spv" };
	};
}

#endif // CTENG_H