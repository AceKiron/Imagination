#include "imaginationpch.h"
#include "Buffer.h"

#include "RendererAPI.h"

#include "../OpenGL/OpenGLBuffer.h"

namespace Imagination {
	namespace Graphics {

		VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {
			switch (RendererAPI::GetAPI()) {
				case RendererAPI::API::OpenGL:
					return new OpenGLVertexBuffer(vertices, size);
			}
		}

		IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count) {
			switch (RendererAPI::GetAPI()) {
				case RendererAPI::API::OpenGL:
					return new OpenGLIndexBuffer(indices, count);
			}
		}

	}
}