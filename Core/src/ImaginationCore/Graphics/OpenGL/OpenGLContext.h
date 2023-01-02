#pragma once

#include "../Base/GraphicsContext.h"

struct GLFWwindow;

namespace Imagination {
	namespace Graphics {

		class OpenGLContext : public GraphicsContext {
		public:
			OpenGLContext(GLFWwindow* windowHandle);

			virtual void Init() override;
			virtual void SwapBuffers() override;
		private:
			GLFWwindow* m_WindowHandle;
		};

	}
}