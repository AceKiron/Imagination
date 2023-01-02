#include "imaginationpch.h"
#include "OpenGLWindow.h"

#include "../../Events/ApplicationEvents.h"
#include "../../Events/KeyEvents.h"
#include "../../Events/MouseEvents.h"

namespace Imagination {
	namespace Graphics {

		static bool s_GLFWInitialized = false;

		static void GLFWErrorCallback(int error, const char* description) {
			IMAGINATION_DEBUG_BREAK("GLFW Error ({0}): {1}", error, description);
		}

		OpenGLWindow::OpenGLWindow(const WindowProps& props) {
			m_Data.Title = props.Title;
			m_Data.Width = props.Width;
			m_Data.Height = props.Height;
			m_Data.VSync = props.VSync;

			if (!s_GLFWInitialized) {
				IMAGINATION_ASSERT(glfwInit(), "Could not initialize GLFW!");
				glfwSetErrorCallback(GLFWErrorCallback);
				s_GLFWInitialized = true;
			}

			m_Window = glfwCreateWindow((int) m_Data.Width, (int) m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);

			m_Context = new OpenGLContext(m_Window);
			m_Context->Init();

			glfwSetWindowUserPointer(m_Window, &m_Data);
			
			SetVSync(true);
			
			glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
				WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
				
				data.EventCallback(Events::WindowCloseEvent());
			});

			glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
				WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

				data.Width = width;
				data.Height = height;

				data.EventCallback(Events::WindowResizeEvent(width, height));
			});

			glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) {
				WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

				switch (focused) {
					case GLFW_TRUE:
						data.Focused = true;
						data.EventCallback(Events::WindowFocusEvent());
						break;

					case GLFW_FALSE:
						data.Focused = false;
						data.EventCallback(Events::WindowLostFocusEvent());
						break;
				}
			});

			glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos) {
				WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

				data.EventCallback(Events::WindowMovedEvent(xpos, ypos));
			});

			glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
				WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

				switch (action) {
					case GLFW_PRESS:
						data.EventCallback(Events::KeyPressedEvent(key, 0));
						break;

					case GLFW_RELEASE:
						data.EventCallback(Events::KeyReleasedEvent(key));
						break;

					case GLFW_REPEAT:
						data.EventCallback(Events::KeyPressedEvent(key, 1));
						break;
				}
			});

			glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keyCode) {
				WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

				data.EventCallback(Events::KeyTypedEvent(keyCode));
			});

			glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
				WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

				switch (action) {
					case GLFW_PRESS:
						data.EventCallback(Events::MouseButtonPressedEvent(button));
						break;

					case GLFW_RELEASE:
						data.EventCallback(Events::MouseButtonReleasedEvent(button));
						break;
				}
			});

			glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				data.EventCallback(Events::MouseScrolledEvent((float) xOffset, (float) yOffset));
			});

			glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				data.EventCallback(Events::MouseMovedEvent((float) xPos, (float) yPos));
			});

#ifdef IMAGINATION_CONSTRUCTOR_LOG_ADDRESS
			IMAGINATION_LOG_INFO("Constructed OpenGLWindow object at {0}.", fmt::ptr(this));
#else
			IMAGINATION_LOG_INFO("Constructed OpenGLWindow object.");
#endif
		}

		OpenGLWindow::~OpenGLWindow() {
			glfwDestroyWindow(m_Window);

			IMAGINATION_LOG_INFO("Destructed OpenGLWindow object.");
		}

		void OpenGLWindow::OnUpdate() {
			glfwPollEvents();
			m_Context->SwapBuffers();
		}

		void OpenGLWindow::SetVSync(bool enabled) {
			glfwSwapInterval(enabled ? 1 : 0);

			m_Data.VSync = enabled;
		}

		bool OpenGLWindow::IsVSync() const {
			return m_Data.VSync;
		}

	}
}