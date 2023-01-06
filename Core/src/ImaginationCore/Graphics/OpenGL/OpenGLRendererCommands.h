#pragma once

#include "../Base/RendererCommands.h"

namespace Imagination {
	namespace Graphics {

		class OpenGLRendererCommands : public RendererCommands {
		public:
			virtual void Init() override;
			virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
			virtual void SetClearColor(const glm::vec4& color) override;
			virtual void Clear() override;
			virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
		};

	}
}