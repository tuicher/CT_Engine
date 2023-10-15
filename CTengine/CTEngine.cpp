#include "CTEngine.hpp"

namespace CTE
{
	void CTEngine::run()
	{
		while (!CTEwindow.shouldClose())
		{
			glfwPollEvents();
		}
	}  
}