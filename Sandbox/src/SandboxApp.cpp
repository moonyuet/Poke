#include <Poke.h>

#include "imgui/imgui.h"
#include "Poke/Platform/OpenGL/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



class ExampleLayer : public Poke::Layer
{
	public:
		ExampleLayer()
			: Layer("Example"), m_CameraController(1280.0f / 720.0f, true)
		{
			m_VertexArray.reset(Poke::VertexArray::Create());
			

			float vertices[3 * 7] = {
				-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
				 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
				 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
			};
			Poke::Ref<Poke::VertexBuffer> vertexBuffer;
			vertexBuffer.reset(Poke::VertexBuffer::Create(vertices, sizeof(vertices)));

			Poke::BufferLayout layout = {
					{Poke::ShaderDataType::Float3, "a_Position"},
					{Poke::ShaderDataType::Float4, "a_color"}

			};
			vertexBuffer->SetLayout(layout);
			m_VertexArray->AddVertexBuffer(vertexBuffer);

			uint32_t indices[3] = { 0, 1, 2 };
			Poke::Ref<Poke::IndexBuffer> indexBuffer;
			indexBuffer.reset(Poke::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
			m_VertexArray->AddIndexBuffer(indexBuffer);

			m_SquareVA.reset(Poke::VertexArray::Create());

			float squareVertices[5 * 4] = {
				-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
				 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
				 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
				-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
			};
			Poke::Ref<Poke::VertexBuffer> squareVB;
			squareVB.reset(Poke::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
			squareVB->SetLayout({
					{Poke::ShaderDataType::Float3, "a_Position"},
					{Poke::ShaderDataType::Float2, "a_TexCoord"}
				});
			m_SquareVA->AddVertexBuffer(squareVB);

			uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
			Poke::Ref<Poke::IndexBuffer> squareIB;
			squareIB.reset(Poke::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
			m_SquareVA->AddIndexBuffer(squareIB);

			std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

			std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

			m_Shader= Poke::Shader::Create("VertexPosColor",vertexSrc, fragmentSrc);
			

			std::string flatColorShadervertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
	
			out vec3 v_Position;
		

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

			std::string flatColorShaderfragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

			m_FlatColorShader= Poke::Shader::Create("FlatColor",flatColorShadervertexSrc, flatColorShaderfragmentSrc);

			auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");
			m_Texture = Poke::Texture2D::Create("assets/texture/TK018_basecolor.png");
			m_cameraTexture = Poke::Texture2D::Create("assets/texture/camera.png");

			std::dynamic_pointer_cast<Poke::OpenGLShader>(textureShader)->Bind();
			std::dynamic_pointer_cast<Poke::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);

		}

		void OnUpdate(Poke::Timestep ts) override
		{
			//Update
			m_CameraController.OnUpdate(ts);

			//Render
			Poke::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			Poke::RenderCommand::Clear();

			Poke::Renderer::BeginScene(m_CameraController.GetCamera());

			glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

			std::dynamic_pointer_cast<Poke::OpenGLShader>(m_FlatColorShader)->Bind();
			std::dynamic_pointer_cast<Poke::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

			for (int y = 0; y < 20; y++)
			{
				for (int x=0; x < 20; x++)
				{
					glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
					glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				
					Poke::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
				}
			}

			auto textureShader = m_ShaderLibrary.Get("Texture");

			m_Texture->Bind();
			Poke::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

			m_cameraTexture->Bind();
			Poke::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

			//Triangle
			//Poke::Renderer::Submit(m_Shader, m_VertexArray);

			Poke::Renderer::EndScene();
		}

		virtual void OnImGuiRender() override
		{
			ImGui::Begin("Settings");
			ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
			ImGui::End();
		}
		void OnEvent(Poke::Event& event) override
		{
			m_CameraController.OnEvent(event);
		}

private:
	Poke::ShaderLibrary m_ShaderLibrary;
	Poke::Ref<Poke::Shader>m_Shader;
	Poke::Ref<Poke::VertexArray> m_VertexArray;

	Poke::Ref<Poke::Shader>m_FlatColorShader;
	Poke::Ref<Poke::VertexArray> m_SquareVA;

	Poke::Ref<Poke::Texture2D> m_Texture, m_cameraTexture;

	Poke::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
	
	};
	class  Sandbox :public Poke::App
	{
	public:
		Sandbox()
		{
			PushLayer(new ExampleLayer());
		}
		~Sandbox()
		{

		}
	};


	Poke::App* Poke::CreateApp()
	{
		return new Sandbox();
	}

