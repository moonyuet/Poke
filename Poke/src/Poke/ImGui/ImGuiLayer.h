#pragma once
#include "Poke/Core/Layer.h"

#include "Poke/Events/KeyEvent.h"
#include "Poke/Events/MouseEvent.h"
#include "Poke/Events/ApplicationEvent.h"

namespace Poke {

	class POKE_API ImGuiLayer :public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;
		void Begin();
		void End();


	private:
		float m_Time = 0.0f;
	};
}