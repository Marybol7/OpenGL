#pragma once 

#include <string>

class Window {

public:

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
};