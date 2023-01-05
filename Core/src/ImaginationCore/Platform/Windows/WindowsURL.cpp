#include "imaginationpch.h"
#include "WindowsURL.h"

namespace Imagination {
	namespace Platform {

		void WindowsURL::OpenInDefaultBrowser() const {
			IMAGINATION_LOG_INFO("Opening URL: {0}.", m_Url);

			std::stringstream ss;
			ss << "start " << m_Url;
			system(ss.str().c_str());
		}

	}
}