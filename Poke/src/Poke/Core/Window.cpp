#include "pkpch.h"
#include "Window.h"

#ifdef PK_PLATFORM_WINDOWS
	#include "Poke/Platform/WindowWindow.h"
#endif
namespace Poke {
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef PK_PLATFORM_WINDOWS
		return CreateScope<WindowWindow>(props);
#else
		PK_CORE_ASSERT(false, "Unknown Platform!");
		return nullptr;
#endif
	}
}