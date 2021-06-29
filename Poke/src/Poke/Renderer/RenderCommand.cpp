#include "pkpch.h"
#include "RenderCommand.h"

#include "Poke/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Poke {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}