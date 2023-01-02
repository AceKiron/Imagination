#pragma once

#include "../Base/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "OpenGLContext.h"

namespace Imagination {
	namespace Graphics {

		class OpenGLWindow : public Window {
		public:
			OpenGLWindow(const WindowProps& props);
			virtual ~OpenGLWindow() override;

			void OnUpdate() override;

			inline unsigned int GetWidth() const override { return m_Data.Width; }
			inline unsigned int GetHeight() const override { return m_Data.Height; }

			inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

			void SetVSync(bool enabled) override;
			bool IsVSync() const override;

			inline virtual void* GetNativeWindow() const override { return m_Window; }

		private:
			GLFWwindow* m_Window;
			GraphicsContext* m_Context;

			struct WindowData
			{
				std::string Title;
				uint32_t Width, Height;
				bool VSync, Focused;
				int PositionX, PositionY;

				EventCallbackFn EventCallback;
			};

			WindowData m_Data;
		};

	}
}