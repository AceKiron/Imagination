#pragma once

#include "../../Core.h"

#include "ShaderProgram.h"

namespace Imagination {
	namespace Graphics {

		class ShaderLibrary {
		public:
			ShaderLibrary();
			~ShaderLibrary();

			static bool Add(std::shared_ptr<ShaderProgram> program);
			static bool Remove(std::shared_ptr<ShaderProgram> program);
			static bool Exists(std::shared_ptr<ShaderProgram> program);

		private:
			static ShaderLibrary* s_Instance;

			std::vector<std::shared_ptr<ShaderProgram>> m_Programs;
		};

	}
}