#include "imaginationpch.h"
#include "RendererCommands.h"

#include "RendererAPI.h"

#include "../OpenGL/OpenGLRendererCommands.h"

namespace Imagination {
	namespace Graphics {

		RendererCommands* RendererCommands::Create() {
			switch (RendererAPI::GetAPI()) {
				case RendererAPI::API::OpenGL:
					return new OpenGLRendererCommands();
			}

			IMAGINATION_LOG_WARN("Unknown RendererAPI in abstract RendererCommands class.");
			return nullptr;
		}

	}
}