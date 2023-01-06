#include "imaginationpch.h"
#include "URL.h"

#include "../Windows/WindowsURL.h"

namespace Imagination {
	namespace Platform {

		URL* URL::Create(std::string url) {
			switch (Platform::GetPlatform()) {
				case Platform::PlatformEnum::Windows:
					return new WindowsURL(url);
			}

			IMAGINATION_LOG_WARN("Unknown Platform in abstract URL class.");
			return nullptr;
		}

	}
}