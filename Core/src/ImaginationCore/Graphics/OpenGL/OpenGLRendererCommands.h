#pragma once

#include "../Base/RendererCommands.h"

namespace Imagination {
	namespace Graphics {

		class OpenGLRendererCommands : public RendererCommands {
		public:
			virtual void SetClearColor(const glm::vec4& color) override;
			virtual void Clear() override;
		};

	}
}