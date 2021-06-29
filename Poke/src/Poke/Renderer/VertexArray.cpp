#include "pkpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Poke/Platform/OpenGL/OpenGLVertexArray.h"

namespace Poke {
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: PK_CORE_ASSERT(false, "RendererAPI::None is currently not supported");  return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLVertexArray();

		}

		PK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}