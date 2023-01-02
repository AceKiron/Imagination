#pragma once

#include "../../Core.h"

#include "Layer.h"

namespace Imagination {
	namespace Graphics {

		class LayerStack {
		public:
			LayerStack();
			~LayerStack();

			void AttachLayer(Layer* layer);
			void AttachOverlay(Layer* overlay);

			void DetachLayer(Layer* layer);
			void DetachOverlay(Layer* overlay);

			//void OnUpdate();

			inline const std::vector<Layer*>& GetLayers() const { return m_Layers; }
			inline const std::vector<Layer*>& GetOverlays() const { return m_Overlays; }

		private:
			std::vector<Layer*> m_Layers;
			std::vector<Layer*> m_Overlays;
		};

	}
}