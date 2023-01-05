#pragma once

#include "Platform.h"

namespace Imagination {
	namespace Platform {

		class URL {
		protected:
			URL(std::string url) : m_Url(url) {}

			std::string m_Url;

		public:
			static URL* Create(std::string url);

			virtual void OpenInDefaultBrowser() const = 0;
		};

	}
}