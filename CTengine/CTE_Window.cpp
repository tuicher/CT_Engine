#include "CTE_Window.hpp"
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
}
