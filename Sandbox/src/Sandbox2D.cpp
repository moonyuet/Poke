#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f), m_SquareColor({0.2f, 0.3f, 0.8f, 1.0f})
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

	//Render
		Poke::Renderer2D::ResetStats();
	{	
		//Reset Stats here
		PK_PROFILE_SCOPE("Renderer Prep");
		Poke::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Poke::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 60.0f;
		PK_PROFILE_SCOPE("Renderer Draw");
		Poke::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Poke::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Poke::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Poke::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Poke::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_FabricTexture, 10.0f);
		Poke::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_FabricTexture, 20.0f);
		Poke::Renderer2D::EndScene();

		Poke::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = {( x + 0.5f )/ 10.0f, 0.4f, (y + 5.0f) /10.f, 1.0f};
				Poke::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Poke::Renderer2D::EndScene();
	}

}

void Sandbox2D::OnImGuiRender()
{
	PK_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	auto stats = Poke::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
	
}


void Sandbox2D::OnEvent(Poke::Event& event)
{
	m_CameraController.OnEvent(event);
}
