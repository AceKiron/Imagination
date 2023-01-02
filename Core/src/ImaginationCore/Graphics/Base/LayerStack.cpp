#include "imaginationpch.h"
#include "LayerStack.h"

namespace Imagination {
	namespace Graphics {

		LayerStack::LayerStack() {
			m_Layers = std::vector<Layer*>();
			m_Overlays = std::vector<Layer*>();

#ifdef IMAGINATION_CONSTRUCTOR_LOG_ADDRESS
			IMAGINATION_LOG_INFO("Constructed LayerStack object at {0}.", fmt::ptr(this));
#else
			IMAGINATION_LOG_INFO("Constructed LayerStack object.");
#endif
		}

		LayerStack::~LayerStack() {
			for (Layer* layer : m_Layers) delete layer;
			for (Layer* layer : m_Overlays) delete layer;

			IMAGINATION_LOG_INFO("Destructed LayerStack object.");
		}

		void LayerStack::AttachLayer(Layer* layer) {
			m_Layers.push_back(layer);
			layer->OnAttach();
		}

		void LayerStack::AttachOverlay(Layer* overlay) {
			m_Overlays.push_back(overlay);
			overlay->OnAttach();
		}

		void LayerStack::DetachLayer(Layer* layer) {
			auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
			if (it != m_Layers.end()) {
				layer->OnDetach();
				m_Layers.erase(it);
			}
		}

		void LayerStack::DetachOverlay(Layer* overlay) {
			auto it = std::find(m_Overlays.begin(), m_Overlays.end(), overlay);
			if (it != m_Overlays.end()) {
				overlay->OnDetach();
				m_Overlays.erase(it);
			}
		}

	}
}