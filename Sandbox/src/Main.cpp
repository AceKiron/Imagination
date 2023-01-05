#include <ImaginationCore/EntryPoint.h>
#include <Imagination.h>

#include <glm/gtc/matrix_transform.hpp>

class SandboxLayer : public Imagination::Graphics::Layer {
private:
	std::shared_ptr<Imagination::Graphics::CameraController> m_CameraController;
	std::shared_ptr<Imagination::Graphics::ShaderProgram> m_Shader;
	std::shared_ptr<Imagination::Graphics::VertexArray> m_VertexArray;

	glm::mat4 m_Transform;

public:
	SandboxLayer() : Imagination::Graphics::Layer("SandboxLayer") {
		m_CameraController.reset(new Imagination::Graphics::OrthographicCameraController(1280.0f / 720.0f, 1.2f));
		m_Shader.reset(Imagination::Graphics::ShaderProgram::Create("assets/shaders/vertexShader.glsl", "assets/shaders/fragmentShader.glsl"));
		m_VertexArray.reset(Imagination::Graphics::VertexArray::Create());

		glm::vec3 Position = glm::vec3(0.25f);
		glm::vec3 Rotation = glm::vec3(0.0f, 0.0f, 45.0f);
		glm::vec3 Scale = glm::vec3(.5f);

		m_Transform = glm::scale(glm::mat4(1.0f), Scale);
		m_Transform = glm::rotate(m_Transform, glm::radians(Rotation.y), glm::vec3(-1, 0, 0));
		m_Transform = glm::rotate(m_Transform, glm::radians(Rotation.x), glm::vec3(0, 1, 0));
		m_Transform = glm::rotate(m_Transform, glm::radians(Rotation.z), glm::vec3(0, 0, 1));
		m_Transform = glm::translate(m_Transform, Position);

		std::shared_ptr<Imagination::Graphics::VertexBuffer> vertexBuffer;
		std::shared_ptr<Imagination::Graphics::IndexBuffer> indexBuffer;

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};
		uint32_t indices[3] = { 0, 1, 2 };

		vertexBuffer.reset(Imagination::Graphics::VertexBuffer::Create(vertices, sizeof(vertices)));
		indexBuffer.reset(Imagination::Graphics::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		Imagination::Graphics::BufferLayout layout = {
			{ Imagination::Graphics::ShaderDataType::Float3, "a_Position" },
			{ Imagination::Graphics::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		
		m_VertexArray->AddVertexBuffer(vertexBuffer);
		m_VertexArray->SetIndexBuffer(indexBuffer);
	}

	void OnUpdate() override {
		m_CameraController->OnUpdate();

		Imagination::Graphics::Renderer::BeginScene(m_CameraController->GetCamera());

		Imagination::Graphics::Renderer::Submit(m_Shader, m_VertexArray, m_Transform);

		Imagination::Graphics::Renderer::EndScene();
	}
};

class SandboxApplication : public Imagination::Application {
private:
	SandboxLayer* m_DockLayer;
public:
	SandboxApplication(const Imagination::Graphics::WindowProps& props) : Imagination::Application(props) {
		m_DockLayer = new SandboxLayer();
		AttachOverlay(m_DockLayer);
	}

	~SandboxApplication() {
		delete m_DockLayer;
	}
};

Imagination::Application* Imagination::CreateApplication() {
	Imagination::Graphics::WindowProps props;

	return new SandboxApplication(props);
}