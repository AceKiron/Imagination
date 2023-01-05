#include "imaginationpch.h"
#include "CameraController.h"

namespace Imagination {
	namespace Graphics {

		OrthographicCameraController::OrthographicCameraController(float aspectRatio, float zoomLevel) {
			m_Camera.reset(new OrthographicCamera(-aspectRatio * zoomLevel, aspectRatio * zoomLevel, -zoomLevel, zoomLevel));
		}

		void OrthographicCameraController::OnUpdate() {
		}

	}
}