#include <ImaginationCore/EntryPoint.h>

#include "Layers.h"

class DockApplication : public Imagination::Application {
private:
	DockLayer* m_DockLayer;
public:
	DockApplication(const Imagination::Graphics::WindowProps& props) : Imagination::Application(props) {
		m_DockLayer = new DockLayer();
		AttachOverlay(m_DockLayer);
	}

	~DockApplication() {
		delete m_DockLayer;
	}
};

Imagination::Application* Imagination::CreateApplication() {
	Imagination::Graphics::WindowProps props;

	return new DockApplication(props);
}