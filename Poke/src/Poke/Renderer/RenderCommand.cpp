#include "pkpch.h"
#include "RenderCommand.h"

#include "Poke/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Poke {
	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();
}