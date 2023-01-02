#include "imaginationpch.h"
#include "OpenGLRendererCommands.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Imagination {
	namespace Graphics {

		void OpenGLRendererCommands::SetClearColor(const glm::vec4& color) {
			glClearColor(color.r, color.g, color.b, color.a);
		}

		void OpenGLRendererCommands::Clear() {
			glClear(GL_COLOR_BUFFER_BIT);
		}

	}
}