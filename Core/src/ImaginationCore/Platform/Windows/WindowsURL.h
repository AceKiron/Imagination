#pragma once

#include "../Base/URL.h"

namespace Imagination {
	namespace Platform {

		class WindowsURL : public URL {
		public:
			WindowsURL(std::string url) : URL(url) {}
			
			virtual void OpenInDefaultBrowser() const override;
		};

	}
}