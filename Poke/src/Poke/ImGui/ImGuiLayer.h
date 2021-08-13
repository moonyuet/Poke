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

		void BlockEvents(bool block) { m_BlockEvents = block; }
		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}