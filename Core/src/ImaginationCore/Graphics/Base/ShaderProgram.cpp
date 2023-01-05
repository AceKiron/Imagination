#include "imaginationpch.h"
#include "ShaderProgram.h"

#include "RendererAPI.h"

#include "../OpenGL/OpenGLShaderProgram.h"

namespace Imagination {
	namespace Graphics {

		ShaderProgram* ShaderProgram::Create(std::string vertexFilename, std::string fragmentFilename) {
			switch (RendererAPI::GetAPI()) {
				case RendererAPI::API::OpenGL:
					return new OpenGLShaderProgram(vertexFilename, fragmentFilename);
			}
		}

	}
}