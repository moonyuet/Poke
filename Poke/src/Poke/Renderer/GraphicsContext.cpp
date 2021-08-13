#include "pkpch.h"
#include "Poke/Renderer/GraphicsContext.h"

#include "Poke/Renderer/Renderer.h"
#include "Poke/Platform/OpenGL/OpenGLContext.h"

namespace Poke {

	Scope<GraphicsContext>GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: PK_CORE_ASSERT(false, "RendererAPI::None is currently not supported");  return nullptr;
		case RendererAPI::API::OpenGL: return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));

		}

		PK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}