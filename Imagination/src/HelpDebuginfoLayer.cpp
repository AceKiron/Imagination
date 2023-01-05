#include "Layers.h"

HelpAboutLayer::HelpAboutLayer() : MyLayerSubclass("HelpAboutLayer", false) {
	std::stringstream ss;
	ss << "Version: " << IMAGINATION_VERSION << std::endl;
#ifdef IMAGINATION_CONFIGURATION_DEBUG
	ss << "Configuration: Debug" << std::endl;
#else
#ifdef IMAGINATION_CONFIGURATION_RELEASE
	ss << "Configuration: Release" << std::endl;
#else
	ss << "Configuration: Dist" << std::endl;
#endif
#endif
	
	ss << std::endl << "Thanks for using our software. :)";

	m_About = ss.str();
}

void HelpAboutLayer::OnImGuiRender() {
	if (m_Active) {
		ImGui::Begin("About Imagination", &m_Active);
		ImGui::Text(m_About.c_str());
		ImGui::End();
	}
}