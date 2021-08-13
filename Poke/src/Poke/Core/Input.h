#pragma once

#include "Base.h"
#include "KeyCodes.h"
#include "MouseCodes.h"
namespace Poke {
	class  Input
	{
	
	public:
		static bool IsKeyPressed(KeyCode key);
		
	private:
		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}