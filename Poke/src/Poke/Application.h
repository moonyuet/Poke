#pragma once
#include "Core.h"

#include "Window.h"
#include "Poke/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

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
		inline static App& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		static App* s_Instance;
	};
	
	App* CreateApp();
}
