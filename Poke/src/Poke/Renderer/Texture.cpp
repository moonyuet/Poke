#include "pkpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Poke/Platform/OpenGL/OpenGLTexture.h"

namespace Poke {
	Ref<Texture2D>Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: PK_CORE_ASSERT(false, "RendererAPI::None is currently not supported");  return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);

		}

		PK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
