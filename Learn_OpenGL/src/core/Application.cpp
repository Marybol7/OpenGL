#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.h"


Application::Application()
{
	m_window = new Window(800, 600, "OpenGLWindow");
}

Application::~Application()
{
	delete m_window;
}	

int Application::Run()
{
	Init();
	while (m_window->IsOpen())
	{
		Update();
		Render();

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
	if ( glfwGetKey(m_window->GetNativeWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		m_window->Close();
	}

}	

void Application::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	m_window->SwapBuffers();
	m_window->PollEvents();
}	


void Application::Shutdown()
{
}	


