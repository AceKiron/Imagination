#include <Imagination.h>
#include <ImaginationCore/EntryPoint.h>

#include <imgui.h>

class SandboxLayer : public Imagination::Graphics::Layer {
public:
	SandboxLayer() : Imagination::Graphics::Layer("SandboxLayer") {

	}

	void OnImGuiRender() override {
		ImGui::Begin("Hello world!");
		ImGui::Text("Lorem Ipsum blah blah blah...");
		ImGui::End();
	}
};

class SandboxApplication : public Imagination::Application {
public:
	SandboxApplication(const Imagination::Graphics::WindowProps& props) : Imagination::Application(props) {
		AttachLayer(new SandboxLayer());
		//IMAGINATION_SET_EVENT_CALLBACK(SandboxApplication::OnEvent);
	}

	/*void OnEvent(Imagination::Events::Event& event) {
		Imagination::Application::OnEvent(event);

		IMAGINATION_LOG_WARN(event.ToString());
	}*/
};

Imagination::Application* Imagination::CreateApplication() {
	Imagination::Graphics::WindowProps props;

	return new SandboxApplication(props);
}