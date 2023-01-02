#pragma once

#include "../Base/ImGuiLayer.h"

namespace Imagination {
	namespace Graphics {

		class OpenGLImGuiLayer : public ImGuiLayer {
		public:
			virtual void OnAttach() override;
			virtual void OnDetach() override;

			virtual void Begin() override;
			virtual void End() override;
		};

	}
}