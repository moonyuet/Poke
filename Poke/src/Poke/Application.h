#pragma once
#include "Core.h"

#include "Window.h"
#include "Poke/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"


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
		bool m_Running = true;
		LayerStack m_LayerStack;
		static App* s_Instance;
	
	};
	
	App* CreateApp();
}
