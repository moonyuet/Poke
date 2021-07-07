#pragma once
#include "Poke.h"

class Sandbox2D : public Poke::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Poke::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Poke::Event& event) override;
private:
	
	Poke::OrthographicCameraController m_CameraController;

	Poke::Ref<Poke::VertexArray> m_SquareVA;
	Poke::Ref<Poke::Shader> m_FlatColorShader;

	Poke::Ref<Poke::Texture2D> m_FabricTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f ,1.0f};
};

