#ifndef CTE_WINDOW_H
#define CTE_WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace CTE
{
	class CTE_Window
	{
	public:
		CTE_Window(const unsigned int &width = 800, const unsigned int &height = 400, std::string name = "Default CTEngine");
		~CTE_Window();

		CTE_Window(const CTE_Window&) = delete;
		CTE_Window& operator=(const CTE_Window&) = delete;

		inline bool shouldClose() { return glfwWindowShouldClose(window); }
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

		inline int getHeight() { return height; }
		inline int getWidth() { return width; }
	private:

		void initWindow();

		const int width, height;
		
		std::string windowName;
		GLFWwindow* window;
	};

}
#endif // !CTE_WINDOW_H