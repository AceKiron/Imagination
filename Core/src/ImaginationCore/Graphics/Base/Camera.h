#pragma once

#include <glm/glm.hpp>

namespace Imagination {
	namespace Graphics {

		class Camera {
		public:
			inline const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
			inline const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
			inline const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

			inline const glm::vec3& GetPosition() const { return m_Position; }
			inline void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); }

			inline const glm::vec3& GetRotation() const { return m_Rotation; }
			inline void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		protected:
			glm::mat4 m_ProjectionMatrix, m_ViewMatrix, m_ViewProjectionMatrix;

			glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
			glm::vec3 m_Rotation = { 0.0f, 0.0f, 0.0f };

			virtual void RecalculateViewMatrix() = 0;
		};

		class OrthographicCamera : public Camera {
		public:
			OrthographicCamera(float left, float right, float bottom, float top, float zNear = -1.0f, float zFar = 1.0f);

			void SetProjection(float left, float right, float bottom, float top, float zNear = -1.0f, float zFar = 1.0f);

		protected:
			virtual void RecalculateViewMatrix() override;
		};

	}
}