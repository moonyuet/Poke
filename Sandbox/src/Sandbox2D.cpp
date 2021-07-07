#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f/720.0f)
{
}

void Sandbox2D::OnAttach()
{
	PK_PROFILE_FUNCTION();

	m_FabricTexture = Poke::Texture2D::Create("assets/texture/TK018_basecolor.png");
}

void Sandbox2D::OnDetach()
{
	PK_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Poke::Timestep ts)
{
	PK_PROFILE_FUNCTION();

	//Update
	
	m_CameraController.OnUpdate(ts); 

	{	//Render
		PK_PROFILE_SCOPE("Renderer Prep");
		Poke::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Poke::RenderCommand::Clear();
	}

	{
		PK_PROFILE_SCOPE("Renderer Draw");
		Poke::Renderer2D::BeginScene(m_CameraController.GetCamera());
		//Poke::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Poke::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Poke::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		//Poke::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_FabricTexture, 10.0f, glm::vec4(1.0f, 0.4f, 0.9f, 1.0f));
		Poke::Renderer2D::EndScene();
	}

}

void Sandbox2D::OnImGuiRender()
{
	PK_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Poke::Event& event)
{
	m_CameraController.OnEvent(event);
}
