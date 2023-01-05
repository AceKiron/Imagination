#pragma once

#include "Events/ApplicationEvents.h"

#include "Graphics/Base/ImGuiLayer.h"
#include "Graphics/Base/LayerStack.h"
#include "Graphics/Base/RendererCommands.h"
#include "Graphics/Base/Window.h"

#define IMAGINATION_SET_EVENT_CALLBACK(x) Imagination::Application::Get().GetWindow().SetEventCallback(std::bind(&x, this, std::placeholders::_1))

namespace Imagination {
	
	class Application {
	public:
		Application(const Graphics::WindowProps& props);

		Application(const Application& other) = delete;

		~Application();

		void OnEvent(Events::Event& event);

		void Run();

		void Stop();

		void AttachLayer(Graphics::Layer* layer) { m_LayerStack->AttachLayer(layer); }
		void AttachOverlay(Graphics::Layer* overlay) { m_LayerStack->AttachOverlay(overlay); }

		void DetachLayer(Graphics::Layer* layer) { m_LayerStack->DetachLayer(layer); }
		void DetachOverlay(Graphics::Layer* overlay) { m_LayerStack->DetachOverlay(overlay); }

		inline Graphics::RendererCommands& GetRendererCommands() const { return *m_Renderer; }
		inline Graphics::Window& GetWindow() const { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool m_Running;

		std::unique_ptr<Graphics::LayerStack> m_LayerStack;
		std::unique_ptr<Graphics::RendererCommands> m_Renderer;
		std::unique_ptr<Graphics::Window> m_Window;
		
		Graphics::ImGuiLayer* m_ImGuiLayer;

		static Application* s_Instance;
	};

	Application* CreateApplication();

}