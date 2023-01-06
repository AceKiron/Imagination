#pragma once

#include <glm/glm.hpp>

#include "VertexArray.h"

namespace Imagination {
	namespace Graphics {

		class RendererCommands {
		public:
			static RendererCommands* Create();

			virtual void Init() = 0;
			virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
			virtual void SetClearColor(const glm::vec4& color) = 0;
			virtual void Clear() = 0;
			virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;
		};

	}
}