#pragma once

#include "../../Core.h"

#include "../../Events/Event.h"

namespace Imagination {
	namespace Graphics {

		struct WindowProps {
			std::string Title = "Hello Imagination!";
			uint32_t Width = 1280;
			uint32_t Height = 720;
			bool VSync = true;
		};

		class Window {
		public:
			using EventCallbackFn = std::function<void(Events::Event&)>;

			static Window* Create(const WindowProps& props = WindowProps());

			virtual ~Window() = default;

			virtual void OnUpdate() = 0;

			inline virtual uint32_t GetWidth() const = 0;
			inline virtual uint32_t GetHeight() const = 0;

			inline virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			inline virtual void* GetNativeWindow() const = 0;
		};

	}
}