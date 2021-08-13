#include "pkpch.h"
#include "Framebuffer.h"
#include "Poke/Renderer/Renderer.h"

#include "Poke/Platform/OpenGL/OpenGLFrameBuffer.h"

namespace Poke {
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: PK_CORE_ASSERT(false, "RendererAPI::None is currently not supported");  return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLFramebuffer>(spec);

		}

		PK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	
}