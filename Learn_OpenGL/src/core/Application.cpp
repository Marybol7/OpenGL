#include "Application.h"


Application::Application()
{
	m_window = new Window(800, 600, "OpenGLWindow");
}

Application::~Application()
{
}	

int Application::Run()
{
	Init();
	while (m_window->IsOpen())
	{
		Update();
		Render();

		m_window->Close(); // For demonstration purposes, we close the window after one iteration

	}
	Shutdown();

	return 0;
}


void Application::Init()
{
	m_window->Show();
}

void Application::Update()
{
}	

void Application::Render()
{
}	


void Application::Shutdown()
{
}	


