#include <ImaginationCore/EntryPoint.h>
#include <Imagination.h>

class SandboxLayer : public Imagination::Graphics::Layer {
private:
	std::shared_ptr<Imagination::Graphics::VertexArray> m_VertexArray;

public:
	SandboxLayer() : Imagination::Graphics::Layer("SandboxLayer") {
		m_VertexArray.reset(Imagination::Graphics::VertexArray::Create());

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
		Imagination::Graphics::Renderer::BeginScene();

		Imagination::Graphics::Renderer::Submit(m_VertexArray);

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