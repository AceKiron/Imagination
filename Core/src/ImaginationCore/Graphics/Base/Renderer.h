#pragma once

#include <glm/glm.hpp>

#include "Camera.h"
#include "ShaderProgram.h"
#include "VertexArray.h"

namespace Imagination {
	namespace Graphics {

		class Renderer {
		public:
			static void Init();
			
			static void BeginScene(const std::shared_ptr<Camera>& camera);
			static void EndScene();

			static void Submit(const std::shared_ptr<ShaderProgram>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		private:
			struct SceneData
			{
				glm::mat4 ViewProjectionMatrix;
			};

			static SceneData* s_SceneData;
		};

	}
}