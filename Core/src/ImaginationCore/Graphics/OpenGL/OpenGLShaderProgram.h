#pragma once

#include "../Base/ShaderProgram.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Imagination {
	namespace Graphics {

		class OpenGLShaderProgram : public ShaderProgram {
		public:
			OpenGLShaderProgram(std::string vertexFilename, std::string fragmentFilename);
			virtual ~OpenGLShaderProgram() override;

			virtual void Bind() const override;
			virtual void Unbind() const override;

		private:
			uint32_t LoadShader(std::string filename, GLenum type);

			uint32_t m_RendererID;
		};

	}
}