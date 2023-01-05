#include <ImaginationCore/EntryPoint.h>
#include <Imagination.h>

class SandboxLayer : public Imagination::Graphics::Layer {
private:
	std::shared_ptr<Imagination::Graphics::CameraController> m_CameraController;
	std::shared_ptr<Imagination::Entities::Entity> m_Entity;
	std::shared_ptr<Imagination::Graphics::ShaderProgram> m_Shader;

public:
	SandboxLayer() : Imagination::Graphics::Layer("SandboxLayer") {
		m_CameraController.reset(new Imagination::Graphics::OrthographicCameraController(1280.0f / 720.0f, 1.2f));
		m_Entity.reset(new Imagination::Entities::Entity());
		m_Shader.reset(Imagination::Graphics::ShaderProgram::Create("assets/shaders/vertexShader.glsl", "assets/shaders/fragmentShader.glsl"));

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};
		uint32_t indices[3] = { 0, 1, 2 };
		Imagination::Graphics::BufferLayout layout = {
			{ Imagination::Graphics::ShaderDataType::Float3, "a_Position" },
			{ Imagination::Graphics::ShaderDataType::Float4, "a_Color" }
		};
		
		m_Entity->AddComponent("sprite", new Imagination::Entities::Components::SpriteComponent(vertices, indices, layout));
		m_Entity->AddComponent("transform", new Imagination::Entities::Components::TransformComponent(glm::vec3(0.25f), glm::vec3(0.0f), glm::vec3(0.5f)));
	}

	void OnUpdate() override {
		m_CameraController->OnUpdate();
		m_Entity->OnUpdate();

		Imagination::Graphics::Renderer::BeginScene(m_CameraController->GetCamera());

		Imagination::Graphics::Renderer::Submit(
			m_Shader,
			m_Entity->GetComponent<Imagination::Entities::Components::SpriteComponent>("sprite").GetVertexArray(),
			m_Entity->GetComponent<Imagination::Entities::Components::TransformComponent>("transform").GetTransform()
		);

		Imagination::Graphics::Renderer::EndScene();
	}
};

class SandboxApplication : public Imagination::Application {
private:
	SandboxLayer* m_SandboxLayer;
public:
	SandboxApplication(const Imagination::Graphics::WindowProps& props) : Imagination::Application(props) {
		m_SandboxLayer = new SandboxLayer();
		AttachOverlay(m_SandboxLayer);
	}

	~SandboxApplication() {
		delete m_SandboxLayer;
	}
};

Imagination::Application* Imagination::CreateApplication() {
	Imagination::Graphics::WindowProps props;

	return new SandboxApplication(props);
}