#include "imaginationpch.h"
#include "Renderer.h"

#include "../../Application.h"

#define RENDERERCOMMANDS Imagination::Application::Get().GetRendererCommands()

namespace Imagination {
	namespace Graphics {

		void Renderer::Init() {
			RENDERERCOMMANDS.Init();
		}

		void Renderer::BeginScene() {

		}

		void Renderer::EndScene() {

		}

		void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform) {
			vertexArray->Bind();
			RENDERERCOMMANDS.DrawIndexed(vertexArray);
		}

	}
}