#pragma once

#include "Poke/Core/Base.h"
namespace Poke {

	struct FramebufferSpecification
	{
		uint32_t Width, Height;
		
		uint32_t Samples = 1;

		bool SwapChainTarget = false;
		
	};
	class Framebuffer 
	{
	public:
		virtual ~Framebuffer() = default;
		virtual const FramebufferSpecification& GetSpecification() const = 0;

		static Ref<Framebuffer> Create(const FramebufferSpecification& spec);

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		virtual void Resize(uint32_t width, uint32_t height) = 0;

		virtual uint32_t GetColorAttachmentRendererID() const = 0;
	};
}