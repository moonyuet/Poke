#include "pkpch.h"
#include "Application.h"
#include "Log.h"

#include "Poke/Renderer/Renderer.h"
#include "Input.h"

#include <GLFW/glfw3.h>

namespace Poke {
#define BIND_EVENT_FN(x) std::bind(&App::x, this, std::placeholders::_1)
	App* App::s_Instance = nullptr;


	App::App()
	{
		PK_PROFILE_FUNCTION();

		PK_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

	}

	App::~App()
	{
		PK_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}
	void App::Close()
	{
		m_Running = false;
	}

	void App::PushLayer(Layer* layer)
	{
		PK_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void App::PushOverlay(Layer* layer)
	{
		PK_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void App::OnEvent(Event& e)
	{
		PK_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
		
		for (auto it = m_LayerStack.begin(); it != m_LayerStack.end(); ++it)
		{
			if (e.m_handled)
				break;
			(*it)->OnEvent(e);
		}

	}

	void App::Run()
	{
		PK_PROFILE_FUNCTION();

		while (m_Running)
		{
			PK_PROFILE_SCOPE("RunLoop");

			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;
			
			if (!m_Minimized)
			{
				{
					PK_PROFILE_SCOPE("LayerStack OnUpdates");

					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}
				
			m_ImGuiLayer->Begin();
			{
				PK_PROFILE_SCOPE("LayerStack OnImGuiRender");

				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
			}
			
			m_ImGuiLayer->End();

			}

			m_Window->OnUpdate();

		}
	}
	bool App::OnWindowClose(WindowCloseEvent& e)
	{
		
		m_Running = false;
		
		return true;
		
	}
	bool App::OnWindowResize(WindowResizeEvent& e)
	{
		PK_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		return false;
	}
}


