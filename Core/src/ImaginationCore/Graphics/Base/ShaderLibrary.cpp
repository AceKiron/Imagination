#include "imaginationpch.h"
#include "ShaderLibrary.h"

namespace Imagination {
	namespace Graphics {

		ShaderLibrary* ShaderLibrary::s_Instance = nullptr;

		ShaderLibrary::ShaderLibrary() {
			IMAGINATION_ASSERT(!s_Instance, "ShaderLibrary class is a Singleton, meaning only one instance can exist at a time.");
			s_Instance = this;

			m_Programs = std::vector<std::shared_ptr<ShaderProgram>>();

#ifdef IMAGINATION_CONSTRUCTOR_LOG_ADDRESS
			IMAGINATION_LOG_INFO("Constructed ShaderLibrary object at {0}.", fmt::ptr(this));
#else
			IMAGINATION_LOG_INFO("Constructed ShaderLibrary object.");
#endif
		}

		ShaderLibrary::~ShaderLibrary() {
			s_Instance = nullptr;

			IMAGINATION_LOG_INFO("Destructed ShaderLibrary object.");
		}

		bool ShaderLibrary::Add(std::shared_ptr<ShaderProgram> program) {
			if (Exists(program)) return false;

			s_Instance->m_Programs.push_back(program);

			return true;
		}

		bool ShaderLibrary::Remove(std::shared_ptr<ShaderProgram> program) {
			for (int i = 0; i < s_Instance->m_Programs.size(); i++) {
				std::shared_ptr<ShaderProgram> programInSingleton = s_Instance->m_Programs[i];

				if (programInSingleton == program) {
					s_Instance->m_Programs.erase(s_Instance->m_Programs.begin() + i);
					return true;
				}
			}

			return false;
		}

		bool ShaderLibrary::Exists(std::shared_ptr<ShaderProgram> program) {
			for (std::shared_ptr<ShaderProgram> programInSingleton : s_Instance->m_Programs) {
				if (programInSingleton == program) return true;
			}

			return false;
		}

	}
}