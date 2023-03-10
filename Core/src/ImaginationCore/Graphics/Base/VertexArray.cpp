#include "imaginationpch.h"
#include "VertexArray.h"

#include "RendererAPI.h"

#include "../OpenGL/OpenGLVertexArray.h"

namespace Imagination {
	namespace Graphics {

		VertexArray* VertexArray::Create() {
			switch (RendererAPI::GetAPI()) {
				case RendererAPI::API::OpenGL:
					return new OpenGLVertexArray();
			}

			IMAGINATION_LOG_WARN("Unknown RendererAPI in abstract VertexArray class.");
			return nullptr;
		}

	}
}