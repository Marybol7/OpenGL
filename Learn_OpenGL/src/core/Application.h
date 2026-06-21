#pragma once 

#include "Window.h"

class Application 
{
public:
	
	Application();
	~Application();
	
	int Run();

private:

	void Init();
	void Update();
	void Render();
	void Shutdown();

private:
	Window m_window;

};