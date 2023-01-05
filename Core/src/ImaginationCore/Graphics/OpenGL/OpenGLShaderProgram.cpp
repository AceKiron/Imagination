#include "imaginationpch.h"
#include "OpenGLShaderProgram.h"

#include "../Base/ShaderLibrary.h"

namespace Imagination {
	namespace Graphics {

		OpenGLShaderProgram::OpenGLShaderProgram(std::string vertexFilename, std::string fragmentFilename) {
			uint32_t vertexShaderID = LoadShader(vertexFilename, GL_VERTEX_SHADER);
			uint32_t fragmentShaderID = LoadShader(fragmentFilename, GL_FRAGMENT_SHADER);

			m_RendererID = glCreateProgram();
			glAttachShader(m_RendererID, vertexShaderID);
			glAttachShader(m_RendererID, fragmentShaderID);
			glLinkProgram(m_RendererID);

			GLint isLinked = 0;
			glGetProgramiv(m_RendererID, GL_LINK_STATUS, (int*)&isLinked);
			if (isLinked == GL_FALSE) {
				GLint maxLength = 0;
				glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &infoLog[0]);

				glDeleteProgram(m_RendererID);

				glDeleteShader(vertexShaderID);
				glDeleteShader(fragmentShaderID);

				IMAGINATION_DEBUG_BREAK(infoLog.data());

				return;
			}

			glDetachShader(m_RendererID, vertexShaderID);
			glDetachShader(m_RendererID, fragmentShaderID);

#ifdef IMAGINATION_CONSTRUCTOR_LOG_ADDRESS
			IMAGINATION_LOG_INFO("Constructed OpenGLShaderProgram object (id={0}) at {1}.", m_RendererID, fmt::ptr(this));
#else
			IMAGINATION_LOG_INFO("Constructed OpenGLShaderProgram object (id={0}).", m_RendererID);
#endif
		}

		OpenGLShaderProgram::~OpenGLShaderProgram() {
			glDeleteProgram(m_RendererID);
		}

		void OpenGLShaderProgram::Bind() const {
			glUseProgram(m_RendererID);
		}

		void OpenGLShaderProgram::Unbind() const {
			glUseProgram(0);
		}

		uint32_t OpenGLShaderProgram::LoadShader(std::string filename, GLenum type) {
			std::string result;
			std::ifstream in(filename, std::ios::in | std::ios::binary);
			IMAGINATION_ASSERT(in, "Could not open file '{0}'!", filename);
			
			in.seekg(0, std::ios::end);
			result.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&result[0], result.size());
			in.close();

			const char* resultC = result.c_str();
			uint32_t shader = glCreateShader(type);
			glShaderSource(shader, 1, &resultC, NULL);
			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE) {
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				IMAGINATION_DEBUG_BREAK(infoLog.data());

				return NULL;
			}

			return shader;
		}

	}
}