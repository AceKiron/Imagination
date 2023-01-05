#include "imaginationpch.h"
#include "OpenGLRendererCommands.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Imagination {
	namespace Graphics {

		void OpenGLRendererCommands::Init() {
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		void OpenGLRendererCommands::SetClearColor(const glm::vec4& color) {
			glClearColor(color.r, color.g, color.b, color.a);
		}

		void OpenGLRendererCommands::Clear() {
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void OpenGLRendererCommands::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) {
			glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
		}

	}
}