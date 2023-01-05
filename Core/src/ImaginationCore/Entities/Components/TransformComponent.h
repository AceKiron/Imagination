#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include "BaseComponent.h"

#include "../../Graphics/Base/VertexArray.h"

namespace Imagination {
	namespace Entities {
		namespace Components {

			class TransformComponent : public BaseComponent {
			public:
				TransformComponent(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : BaseComponent(), m_Position(position), m_Rotation(rotation), m_Scale(scale) {
					RecalculateMatrix();
				}

				inline const glm::mat4& GetTransform() const { return m_Transform; }

				inline const glm::vec3& GetPosition() const { return m_Position; }
				inline void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateMatrix(); }

				inline const glm::vec3& GetRotation() const { return m_Rotation; }
				inline void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation; RecalculateMatrix(); }

				inline const glm::vec3& GetScale() const { return m_Scale; }
				inline void SetScale(const glm::vec3& scale) { m_Scale = scale; RecalculateMatrix(); }

			private:
				void RecalculateMatrix() {
					m_Transform = glm::translate(glm::scale(glm::mat4(1.0f), m_Scale) * glm::toMat4(glm::quat(m_Rotation)), m_Position);
				}

				glm::mat4 m_Transform;
				glm::vec3 m_Position, m_Rotation, m_Scale;
			};

		}
	}
}