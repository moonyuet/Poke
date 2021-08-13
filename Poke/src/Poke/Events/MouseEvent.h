#pragma once
#include "Event.h"
#include "Poke/Core/Input.h"


namespace Poke {
	class  MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y)
			:m_MouseX(x), m_MouseY(y) {}

		float GetX() const { return m_MouseX; }
		float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	
	private:
		float m_MouseX, m_MouseY;
	};

	class  MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset) {}
		
		float GetXOffset() const {return m_XOffset;}
		float GetYOffset() const { return m_YOffset;}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset, m_YOffset;

	};

	class  MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_MouseButton; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	protected:
		MouseButtonEvent(int mouseButton)
			:m_MouseButton(mouseButton) {}

		int m_MouseButton;
	};
	class  MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class  MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}