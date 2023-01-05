#include "imaginationpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Imagination {
	namespace Graphics {

		//////////////////////////
		// VertexBuffer //////////
		//////////////////////////

		OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size) {
			glCreateBuffers(1, &m_RendererID);
			glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
			glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

#ifdef IMAGINATION_CONSTRUCTOR_LOG_ADDRESS
			IMAGINATION_LOG_INFO("Constructed OpenGLVertexBuffer object (id={0}, size={1}) at {2}.", m_RendererID, size, fmt::ptr(this));
#else
			IMAGINATION_LOG_INFO("Constructed OpenGLVertexBuffer object (id={0}, size={1}).", m_RendererID, size);
#endif
		}

		OpenGLVertexBuffer::~OpenGLVertexBuffer() {
			glDeleteBuffers(1, &m_RendererID);

			IMAGINATION_LOG_INFO("Destructed OpenGLVertexBuffer object (id={0}).", m_RendererID);
		}

		void OpenGLVertexBuffer::Bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		}

		void OpenGLVertexBuffer::Unbind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		//////////////////////////
		// IndexBuffer ///////////
		//////////////////////////

		OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count) : m_Count(count)  {
			glCreateBuffers(1, &m_RendererID);
			glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);

#ifdef IMAGINATION_CONSTRUCTOR_LOG_ADDRESS
			IMAGINATION_LOG_INFO("Constructed OpenGLIndexBuffer object (id={0}, count={1}) at {2}.", m_RendererID, count, fmt::ptr(this));
#else
			IMAGINATION_LOG_INFO("Constructed OpenGLIndexBuffer object (id={0}, count={1}).", m_RendererID, count);
#endif
		}

		OpenGLIndexBuffer::~OpenGLIndexBuffer() {
			glDeleteBuffers(1, &m_RendererID);
		}

		void OpenGLIndexBuffer::Bind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		}

		void OpenGLIndexBuffer::Unbind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

	}
}