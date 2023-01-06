#pragma once

#include "BaseComponent.h"

#include "../../Graphics/Base/VertexArray.h"

namespace Imagination {
	namespace Entities {
		namespace Components {

			class SpriteComponent : public BaseComponent {
			public:
				SpriteComponent() : BaseComponent(), m_VertexArray(Imagination::Graphics::VertexArray::Create()) {}

				inline void AddVertexBuffer(float* vertices, uint32_t size, Imagination::Graphics::BufferLayout layout) {
					std::shared_ptr<Imagination::Graphics::VertexBuffer> vertexBuffer;
					vertexBuffer.reset(Imagination::Graphics::VertexBuffer::Create(vertices, size));
					vertexBuffer->SetLayout(layout);
					m_VertexArray->AddVertexBuffer(vertexBuffer);
				}
				
				inline void SetIndexBuffer(uint32_t* indices, uint32_t indicesSize) {
					std::shared_ptr<Imagination::Graphics::IndexBuffer> indexBuffer;
					indexBuffer.reset(Imagination::Graphics::IndexBuffer::Create(indices, indicesSize));
					m_VertexArray->SetIndexBuffer(indexBuffer);
				}

				inline const std::shared_ptr<Imagination::Graphics::VertexArray>& GetVertexArray() const { return m_VertexArray; }
				

			private:
				std::shared_ptr<Imagination::Graphics::VertexArray> m_VertexArray;
			};

		}
	}
}