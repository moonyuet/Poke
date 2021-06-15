#include "pkpch.h"
#include "Application.h"
#include "Log.h"


#include "glad/glad.h"

#include "Poke/Input.h"


namespace Poke {
#define BIND_EVENT_FN(x) std::bind(&App::x, this, std::placeholders::_1)
	App* App::s_Instance = nullptr;

	App::App()
	{
		PK_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

	}

	App::~App()
	{

	}

	void App::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
		
	}

	void App::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void App::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
		PK_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.m_handled)
				break;
		}

	}

	void App::Run()
	{
		while (m_Running)
		{
			glClearColor(1.0f, 0.0f, 1.0f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();

		}
	}
	bool App::OnWindowClose(WindowCloseEvent& e)
	{
		
		m_Running = false;
		
		return true;
		
	}
}


