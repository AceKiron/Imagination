#include "imaginationpch.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Imagination {
	namespace Graphics {

		OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float zNear, float zFar) {
			m_ProjectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
			m_ViewMatrix = glm::mat4(1.0f);

			m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
		}

		void OrthographicCamera::SetProjection(float left, float right, float bottom, float top, float zNear, float zFar) {
			m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
			m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
		}

		void OrthographicCamera::RecalculateViewMatrix() {
			glm::mat4 transform = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.y), glm::vec3(-1, 0, 0));
			transform = glm::rotate(transform, glm::radians(m_Rotation.x), glm::vec3(0, 1, 0));
			transform = glm::rotate(transform, glm::radians(m_Rotation.z), glm::vec3(0, 0, 1));
			transform = glm::translate(transform, m_Position);

			m_ViewMatrix = glm::inverse(transform);
			m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
		}

	}
}