#include "imaginationpch.h"
#include "ImGuiLayer.h"

#include "RendererAPI.h"

#include "../OpenGL/OpenGLImGuiLayer.h"

namespace Imagination {
	namespace Graphics {

		ImGuiLayer* ImGuiLayer::Create() {
			switch (RendererAPI::GetAPI()) {
				case RendererAPI::API::OpenGL:
					return new OpenGLImGuiLayer();
			}
		}

	}
}