#pragma once
#include "Poke.h"
#include "Panel/SceneHierarchyPanel.h"

namespace Poke {

class PokeNeedle : public Layer
{
public:
	PokeNeedle();
	virtual ~PokeNeedle() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Poke::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Poke::Event& event) override;
private:
	
	Poke::OrthographicCameraController m_CameraController;

	Ref<VertexArray> m_SquareVA; 
	Ref<Shader> m_FlatColorShader;
	Ref<Framebuffer> m_Framebuffer;

	Ref<Scene> m_ActiveScene;
	Entity m_SquareEntity;
	Entity m_CameraEntity;
	Entity m_SecondCamera;

	bool m_PrimaryCamera = true;

	Ref<Texture2D> m_FabricTexture;

	bool m_ViewportFocused = false, m_ViewportHovered = false;

	glm::vec2 m_ViewportSize = {0.0f, 0.0f};

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f ,1.0f};

	//Panels
	SceneHierarchyPanel m_SceneHierarchyPanel;
};

}
