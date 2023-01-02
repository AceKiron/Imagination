#pragma once

#include "../../Core.h"

namespace Imagination {
	namespace Graphics {

		class RendererAPI {
		public:
			enum class API
			{
				None = 0, OpenGL = 1
			};
		
			inline static API GetAPI() { return s_API; }

		private:
			static API s_API;
		};

	}
}