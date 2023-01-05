#pragma once

#include "../../Core.h"

namespace Imagination {
	namespace Platform {

		class Platform {
		public:
			enum class PlatformEnum
			{
				None = 0, Windows = 1
			};

			inline static PlatformEnum GetPlatform() { return s_Platform; }

		private:
#ifdef IMAGINATION_PLATFORM_WINDOWS
			const static PlatformEnum s_Platform = PlatformEnum::Windows;
#endif
		};

	}
}