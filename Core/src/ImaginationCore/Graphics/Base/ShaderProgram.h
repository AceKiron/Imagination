#pragma once

#include "../../Core.h"

namespace Imagination {
	namespace Graphics {

		class ShaderProgram {
		public:
			static ShaderProgram* Create(std::string vertexFilename, std::string fragmentFilename);

			virtual ~ShaderProgram() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;
		};

	}
}