#pragma once

#include "../../Core.h"

#include "Buffer.h"

namespace Imagination {
	namespace Graphics {

		class VertexArray {
		public:
			static VertexArray* Create();

			virtual ~VertexArray() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
			virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

			virtual inline const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
			virtual inline const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;
		};

	}
}