#pragma once

#include <glm/glm.hpp>

namespace Imagination {
	namespace Graphics {

		class RendererCommands {
		public:
			static RendererCommands* Create();

			virtual void SetClearColor(const glm::vec4& color) = 0;
			virtual void Clear() = 0;
		};

	}
}