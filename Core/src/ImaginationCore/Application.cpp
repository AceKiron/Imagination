#include "imaginationpch.h"
#include "Application.h"

#include "Core.h"

namespace Imagination {

	Application* Application::s_Instance = nullptr;

	Application::Application(const Graphics::WindowProps& props) {
		IMAGINATION_ASSERT(!s_Instance, "Application class is a Singleton, meaning only one instance can exist at a time.");
		s_Instance = this;

		m_LayerStack.reset(new Graphics::LayerStack());
		m_Renderer.reset(Graphics::RendererCommands::Create());
		m_Window.reset(Graphics::Window::Create(props));

		m_ImGuiLayer = Graphics::ImGuiLayer::Create();

		IMAGINATION_SET_EVENT_CALLBACK(Application::OnEvent);

		m_Running = false;
		m_Minimized = false;

		AttachOverlay(m_ImGuiLayer);

#ifdef IMAGINATION_CONSTRUCTOR_LOG_ADDRESS
		IMAGINATION_LOG_INFO("Constructed Application object at {0}.", fmt::ptr(this));
#else
		IMAGINATION_LOG_INFO("Constructed Application object.");
#endif
	}

	Application::~Application() {
		DetachOverlay(m_ImGuiLayer);

		delete m_ImGuiLayer;

		s_Instance = nullptr;

		IMAGINATION_LOG_INFO("Destructed Application object.");
	}

	void Application::OnEvent(Events::Event& event) {
		switch (event.GetType()) {
			case Events::WindowClose:
				Stop();
				event.MarkHandled();
				break;

			case Events::WindowResize:
				OnWindowResize((Events::WindowResizeEvent&) event);
				event.MarkHandled();
				break;
		}
	}

	void Application::OnWindowResize(Events::WindowResizeEvent& event) {
		if (event.GetVector()->x == 0 || event.GetVector()->y == 0) {
			m_Minimized = true;
			return;
		}

		m_Minimized = false;
		m_Renderer->SetViewport(0, 0, event.GetVector()->x, event.GetVector()->y);
	}

	void Application::Run() {
		m_Running = true;

		while (m_Running) {
			m_Renderer->SetClearColor(glm::vec4(0.1f, 0.1f, 0.1f, 1));
			m_Renderer->Clear();

			if (!m_Minimized) {
				for (Graphics::Layer* layer : m_LayerStack->GetLayers()) layer->OnUpdate();
				for (Graphics::Layer* overlay : m_LayerStack->GetOverlays()) overlay->OnUpdate();

				m_ImGuiLayer->Begin();
				for (Graphics::Layer* layer : m_LayerStack->GetLayers()) layer->OnImGuiRender();
				for (Graphics::Layer* overlay : m_LayerStack->GetOverlays()) overlay->OnImGuiRender();
				m_ImGuiLayer->End();
			}

			m_Window->OnUpdate();
		}
	}

}