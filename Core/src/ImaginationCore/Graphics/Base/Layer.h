#pragma once

#include "../../Core.h"

namespace Imagination {
	namespace Graphics {

		class Layer {
		public:
			Layer(std::string debugName) {
#ifdef IMAGINATION_CONSTRUCTOR_LOG_ADDRESS
				IMAGINATION_LOG_INFO("Constructed Layer object ({0}) at {1}.", debugName, fmt::ptr(this));
#else
				IMAGINATION_LOG_INFO("Constructed Layer object ({0}).", debugName);
#endif
			}

			~Layer() {
				IMAGINATION_LOG_INFO("Destructed Layer object.");
			}

			virtual void OnUpdate() {}
			virtual void OnImGuiRender() {}

			virtual void OnAttach() {}
			virtual void OnDetach() {}
		};

	}
}