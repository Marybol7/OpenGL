#include "Window.h"

Window::Window(int width, int height, const std::string& title)
	: m_width(width), m_height(height), m_title(title), m_isOpen(false) 
{
}

Window::~Window() 
{
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
	return m_isOpen;
}	


