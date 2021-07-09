#pragma once
#include "Base.h"

#include "Window.h"
#include "LayerStack.h"
#include "Poke/Events/Event.h"
#include "Poke/Events/ApplicationEvent.h"

#include "Poke/Core/Timestep.h"

#include "Poke/ImGui/ImGuiLayer.h"

#include "Poke/Renderer/Shader.h"

#include "Poke/Renderer/Buffer.h"

#include "Poke/Renderer/VertexArray.h"

#include "Poke/Renderer/OrthographicCamera.h"
namespace Poke {
	class POKE_API App
	{
		
		
	public:
		App();
		virtual ~App();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		
		inline Window& GetWindow() { return *m_Window; }
		void Close();
		inline static App& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		static App* s_Instance;
	};
	
	App* CreateApp();
}
