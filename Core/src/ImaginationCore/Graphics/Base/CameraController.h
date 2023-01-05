#pragma once

#include "../../Core.h"

#include "Camera.h"

namespace Imagination {
	namespace Graphics {

		class CameraController {
		public:
			inline virtual const std::shared_ptr<Camera>& GetCamera() const { return m_Camera; }

			virtual void OnUpdate() = 0;

		protected:
			std::shared_ptr<Camera> m_Camera;
		};

		class OrthographicCameraController : public CameraController {
		public:
			OrthographicCameraController(float aspectRatio, float zoomLevel);

			virtual void OnUpdate() override;
		};

	}
}