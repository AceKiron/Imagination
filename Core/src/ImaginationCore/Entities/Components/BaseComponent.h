#pragma once

#include "../../Core.h"

namespace Imagination {
	namespace Entities {
		namespace Components {

			class BaseComponent {
			public:
				BaseComponent() {}

				virtual void OnUpdate() {}

				virtual void OnAttach() {}
				virtual void OnDetach() {}
			};

		}
	}
}