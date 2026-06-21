#pragma once 

#include <string>

struct GLFWwindow;

class Window {

public:
	Window();
	Window(int width, int height, const std::string& title);
	~Window();

	void Show();
	void Close();
	bool IsOpen() const;

private: 	
	int m_width;
	int m_height;
	std::string m_title;
	bool m_isOpen;

	GLFWwindow* m_window = NULL;
};