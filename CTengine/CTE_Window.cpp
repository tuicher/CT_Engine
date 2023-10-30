#include "CTE_Window.h"

#include <stdexcept>

namespace CTE
{
	CTE_Window::CTE_Window(const unsigned int& width, const unsigned int& height, std::string name): width(width), height(height), windowName(name)
	{
		initWindow();
	}

	CTE_Window::~CTE_Window()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void CTE_Window::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

	void CTE_Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create window surface!");
		}
	}
}
