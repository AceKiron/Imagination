#pragma once

#include <glm/glm.hpp>

#include "VertexArray.h"

namespace Imagination {
	namespace Graphics {

		class Renderer {
		public:
			static void Init();
			
			static void BeginScene();
			static void EndScene();

			static void Submit(const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		private:
			struct SceneData
			{
				glm::mat4 ViewProjectionMatrix;
			};

			static SceneData* s_SceneData;
		};

	}
}