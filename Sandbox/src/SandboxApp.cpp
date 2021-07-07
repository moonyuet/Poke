#include <Poke.h>
#include <Poke/Core/EntryPoint.h>

#include "imgui/imgui.h"
#include "Poke/Platform/OpenGL/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"


		
class  Sandbox :public Poke::App
{
	public:
		Sandbox()
		{
			PushLayer(new Sandbox2D());

		}
		~Sandbox()
		{

		}
};


Poke::App* Poke::CreateApp()
{
	return new Sandbox();
}

