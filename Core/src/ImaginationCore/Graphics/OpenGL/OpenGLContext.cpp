#include "imaginationpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../../Core.h"

namespace Imagination {
	namespace Graphics {

		OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle) {
			IMAGINATION_ASSERT(windowHandle, "Window handle is null!");
		}

		void OpenGLContext::Init() {
			glfwMakeContextCurrent(m_WindowHandle);

			int success = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
			IMAGINATION_ASSERT(success, "Failed to initialize Glad!");

			IMAGINATION_LOG_INFO("OpenGL Info:");
			IMAGINATION_LOG_INFO("  Vendor: {0}", (const char*) glGetString(GL_VENDOR));
			IMAGINATION_LOG_INFO("  Renderer: {0}", (const char*) glGetString(GL_RENDERER));
			IMAGINATION_LOG_INFO("  Version: {0}", (const char*) glGetString(GL_VERSION));
		}

		void OpenGLContext::SwapBuffers() {
			glfwSwapBuffers(m_WindowHandle);
		}

	}
}