#include "imaginationpch.h"
#include "Renderer.h"

#include "../../Application.h"

#define RENDERERCOMMANDS Imagination::Application::Get().GetRendererCommands()

namespace Imagination {
	namespace Graphics {

		Renderer::SceneData* Renderer::s_SceneData = new Renderer::SceneData();

		void Renderer::Init() {
			RENDERERCOMMANDS.Init();
		}

		void Renderer::BeginScene(const std::shared_ptr<Camera>& camera) {
			s_SceneData->ViewProjectionMatrix = camera->GetViewProjectionMatrix();
		}

		void Renderer::EndScene() {

		}

		void Renderer::Submit(const std::shared_ptr<ShaderProgram>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform) {
			shader->Bind();
			shader->UploadUniformMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
			shader->UploadUniformMat4("u_Transform", transform);

			vertexArray->Bind();
			RENDERERCOMMANDS.DrawIndexed(vertexArray);
		}

	}
}