#include "Layers.h"

DockLayer::DockLayer() : Imagination::Graphics::Layer("DockLayer") {
	m_HelpAboutLayer.reset(new HelpAboutLayer());

	Imagination::Application::Get().AttachOverlay(m_HelpAboutLayer.get());

	m_ManualUrl.reset(Imagination::Platform::URL::Create("https://acekiron.github.io/ImaginationManual"));
	m_ItchIoUrl.reset(Imagination::Platform::URL::Create("https://acekiron.itch.io/imagination"));
}

void DockLayer::OnImGuiRender() {
	// Submit the DockSpace
	static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
	dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;

	ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->WorkPos);
	ImGui::SetNextWindowSize(viewport->WorkSize);
	ImGui::SetNextWindowViewport(viewport->ID);
	window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
	window_flags |= ImGuiWindowFlags_NoBackground;

	if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
		window_flags |= ImGuiWindowFlags_NoBackground;

	ImGui::Begin("1", nullptr, window_flags);

	ImGuiIO& io = ImGui::GetIO();
	ImGui::DockSpace(ImGui::GetID("2"));

	if (ImGui::BeginMenuBar()) {
		if (ImGui::BeginMenu("File")) {
			ImGui::MenuItem("New project");
			ImGui::MenuItem("Open project");
			ImGui::MenuItem("Save project");
			ImGui::MenuItem("Save project as");
			ImGui::Separator();

			ImGui::MenuItem("Run game");
			ImGui::MenuItem("Debug game");
			ImGui::MenuItem("Export game");
			ImGui::Separator();

			ImGui::MenuItem("Preferences");
			if (ImGui::MenuItem("Quit")) Imagination::Application::Get().Stop();

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Window")) {
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Help")) {
			if (ImGui::MenuItem("Manual")) m_ManualUrl->OpenInDefaultBrowser();
			if (ImGui::MenuItem("itch.io page")) m_ItchIoUrl->OpenInDefaultBrowser();
			ImGui::Separator();

			if (ImGui::MenuItem("About")) m_HelpAboutLayer->ToggleActive();

			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}

	ImGui::End();

	ImGuiWindowFlags window_flags_2 = ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoCollapse;

	ImGui::Begin("Inspector", nullptr, window_flags_2);
	/*ImGui::Text("Transform");
	ImGui::DragFloat3("Position", pos, 1.0f);
	ImGui::Spacing();

	ImGui::Text("Sprite component");
	ImGui::Button("Hii");*/	
	ImGui::End();

	ImGui::Begin("Hierarchy", nullptr, window_flags_2);
	/*if (ImGui::TreeNode("Test")) {
		if (ImGui::TreeNode("Test2")) {
			ImGui::TreePop();
		}
		if (ImGui::TreeNode("Test3")) {
			if (ImGui::TreeNode("Test4")) {
				ImGui::TreePop();
			}
			ImGui::TreePop();
		}
		ImGui::TreePop();
	}*/
	ImGui::End();

	ImGui::Begin("Project", nullptr, window_flags_2);
	/*if (ImGui::BeginPopupContextWindow()) {
		if (ImGui::MenuItem("New component")) {
			IMAGINATION_LOG_WARN("NEW CAMERA");
		}

		ImGui::EndPopup();
	}*/
	ImGui::End();
}