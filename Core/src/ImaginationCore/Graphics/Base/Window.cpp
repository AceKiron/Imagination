#include "imaginationpch.h"
#include "Window.h"

#include "RendererAPI.h"

#include "../OpenGL/OpenGLWindow.h"

namespace Imagination {
	namespace Graphics {

		Window* Window::Create(const WindowProps& props) {
			switch (RendererAPI::GetAPI()) {
				case RendererAPI::API::OpenGL:
					return new OpenGLWindow(props);
			}

			IMAGINATION_LOG_WARN("Unknown RendererAPI in abstract Window class.");
			return nullptr;
		}

	}
}