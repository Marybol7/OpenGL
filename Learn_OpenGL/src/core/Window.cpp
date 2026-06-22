#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.h"

Window::Window(int width, int height, const std::string& title)
	: m_width(width), m_height(height), m_title(title), m_isOpen(false) 
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	glfwMakeContextCurrent(m_window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

Window::~Window() 
{
	glfwTerminate();
}	

void Window::Show() 
{
	m_isOpen = true;
}	

void Window::Close() 
{
	m_isOpen = false;
}		

bool Window::IsOpen() const 
{
	return !glfwWindowShouldClose(m_window);
}	

void Window::PollEvents() 
{
	glfwPollEvents();
}

void Window::SwapBuffers() 
{
	glfwSwapBuffers(m_window);
}
