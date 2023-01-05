#pragma once

#include "BaseComponent.h"

#include "../../Graphics/Base/VertexArray.h"

namespace Imagination {
	namespace Entities {
		namespace Components {

			class SpriteComponent : public BaseComponent {
			public:
				SpriteComponent(float* vertices, uint32_t* indices, Imagination::Graphics::BufferLayout layout) : BaseComponent() {
					m_VertexArray.reset(Imagination::Graphics::VertexArray::Create());

					std::shared_ptr<Imagination::Graphics::VertexBuffer> vertexBuffer;
					vertexBuffer.reset(Imagination::Graphics::VertexBuffer::Create(vertices, sizeof(vertices)));
					vertexBuffer->SetLayout(layout);
					m_VertexArray->AddVertexBuffer(vertexBuffer);

					std::shared_ptr<Imagination::Graphics::IndexBuffer> indexBuffer;
					indexBuffer.reset(Imagination::Graphics::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
					m_VertexArray->SetIndexBuffer(indexBuffer);
				}

				inline const std::shared_ptr<Imagination::Graphics::VertexArray>& GetVertexArray() const { return m_VertexArray; }

			private:
				std::shared_ptr<Imagination::Graphics::VertexArray> m_VertexArray;
			};

		}
	}
}