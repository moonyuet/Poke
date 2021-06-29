#include "pkpch.h"

#include "OpenGLContext.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Poke {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		PK_CORE_ASSERT(windowHandle, "Window Handle is null");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PK_CORE_ASSERT(status, "Failed to initialize Glad");

		//PK_CORE_INFO("OpenGL Renderer : ");
		//PK_CORE_INFO(" Vendor : {0}", glGetString(GL_VENDOR));
		//PK_CORE_INFO(" Renderer : {0}", glGetString(GL_RENDERER));

	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}