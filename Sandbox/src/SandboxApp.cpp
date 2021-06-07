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
			PK_INFO("ExampleLayer::Update");
		}
		void OnEvent(Poke::Event& event) override
		{
			PK_TRACE("{0}", event);
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

