#pragma once

#include <imgui.h>

#include "Layer.h"

namespace Imagination {
	namespace Graphics {

		class ImGuiLayer : public Layer {
		public:
			static ImGuiLayer* Create();

			ImGuiLayer() : Layer("ImGuiLayer") {}

			virtual void OnAttach() override = 0;
			virtual void OnDetach() override = 0;

			virtual void Begin() = 0;
			virtual void End() = 0;
		};

	}
}