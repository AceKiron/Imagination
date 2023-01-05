#include "imaginationpch.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

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
			glm::mat4 transform = glm::translate(glm::toMat4(glm::quat(m_Rotation)), m_Position);

			m_ViewMatrix = glm::inverse(transform);
			m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
		}

	}
}