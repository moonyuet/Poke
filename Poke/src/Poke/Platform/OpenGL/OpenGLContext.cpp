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
		PK_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PK_CORE_ASSERT(status, "Failed to initialize Glad");

		//PK_CORE_INFO("OpenGL Renderer : ");
		//PK_CORE_INFO(" Vendor : {0}", glGetString(GL_VENDOR));
		//PK_CORE_INFO(" Renderer : {0}", glGetString(GL_RENDERER));

		#ifdef PK_ENABLE_ASSERTS
			int MajorVer, MinorVer;

			glGetIntegerv(GL_MAJOR_VERSION, &MajorVer);
			glGetIntegerv(GL_MINOR_VERSION, &MinorVer);

			PK_CORE_ASSERT(MajorVer > 4 || (MajorVer == 4 && MinorVer >= 6), "Poke requires at least OpenGL version 4.6!");
		#endif
	}
	void OpenGLContext::SwapBuffers()
	{
		PK_PROFILE_FUNCTION();
		glfwSwapBuffers(m_WindowHandle);
	}
}