#pragma once

#include "Components/BaseComponent.h"

namespace Imagination {
	namespace Entities {

		class Entity {
		public:
			Entity() { IMAGINATION_LOG_INFO("Create new Entity"); }
			~Entity() { IMAGINATION_LOG_INFO("Destroy Entity"); }

			void OnUpdate() const {
				for (const auto& [key, value] : m_Components) {
					value->OnUpdate();
				}
			}

			void AddComponent(std::string key, Imagination::Entities::Components::BaseComponent* value) {
				std::shared_ptr<Imagination::Entities::Components::BaseComponent> ptr;
				ptr.reset(value);
				
				m_Components[key] = ptr;
				value->OnAttach();

				IMAGINATION_LOG_INFO("Added {0} component", typeid(value).name());
			}

			template <class T>
			inline const T& GetComponent(std::string key) const {
				if (auto search = m_Components.find(key); search != m_Components.end()) {
					return *std::dynamic_pointer_cast<T>(search->second);
				}
			}

		private:
			std::map<std::string, std::shared_ptr<Imagination::Entities::Components::BaseComponent>> m_Components;
		};

	}
}