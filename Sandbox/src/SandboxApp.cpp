#include <Poke.h>

class ExampleLayer : public Poke::Layer
{
	public:
		ExampleLayer()
			: Layer("Example")
		{
			
		}

		void OnUpdate() override
		{
			if (Poke::Input::IsKeyPressed(PK_KEY_TAB))
				PK_TRACE("Tab key is pressed(poll)!");
		}
		void OnEvent(Poke::Event& event) override
		{
			if (event.GetEventType() == Poke::EventType::KeyPressed)
			{
				Poke::KeyPressedEvent& e = (Poke::KeyPressedEvent&)event;
				if (e.GetKeyCode() == PK_KEY_TAB)
					PK_TRACE("Tab key is pressed(event)!");
				PK_TRACE("{0}", (char)e.GetKeyCode());
			}
		}
	};
	class  Sandbox :public Poke::App
	{
	public:
		Sandbox()
		{
			PushLayer(new ExampleLayer());
			PushOverlay(new Poke::ImGuiLayer());

		
		}
		~Sandbox()
		{

		}
	};


	Poke::App* Poke::CreateApp()
	{
		return new Sandbox();
	}

