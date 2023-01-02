#pragma once

#include <glm/glm.hpp>

#include "Event.h"

namespace Imagination {
	namespace Events {

		class MouseButtonEvent : public Event {
		public:
			inline int GetMouseButton() const { return m_Button; }

		protected:
			MouseButtonEvent(EventType eventType, int button) : Event(eventType), m_Button(button) {}

			int m_Button;
		};

		class MouseButtonPressedEvent : public MouseButtonEvent {
		public:
			MouseButtonPressedEvent(int button) : MouseButtonEvent(EventType::MouseButtonPressed, button) {}

			virtual std::string ToString() const override {
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << m_Button;
				return ss.str();
			}
		};

		class MouseButtonReleasedEvent : public MouseButtonEvent {
		public:
			MouseButtonReleasedEvent(int button) : MouseButtonEvent(EventType::MouseButtonReleased, button) {}

			virtual std::string ToString() const override {
				std::stringstream ss;
				ss << "MouseButtonReleasedEvent: " << m_Button;
				return ss.str();
			}
		};

		class MouseMovedEvent : public Event {
		public:
			MouseMovedEvent(float x, float y) : Event(EventType::MouseMoved), m_Vector(new glm::vec2(x, y)) {}

			inline glm::vec2* GetVector() const { return m_Vector; }

			virtual std::string ToString() const override {
				std::stringstream ss;
				ss << "MouseMovedEvent: " << m_Vector->x << ", " << m_Vector->y;
				return ss.str();
			}

		private:
			glm::vec2* m_Vector;
		};

		class MouseScrolledEvent : public Event {
		public:
			MouseScrolledEvent(float x, float y) : Event(EventType::MouseScrolled), m_Vector(new glm::vec2(x, y)) {}

			inline glm::vec2* GetVector() const { return m_Vector; }

			virtual std::string ToString() const override {
				std::stringstream ss;
				ss << "MouseScrolledEvent: " << m_Vector->x << ", " << m_Vector->y;
				return ss.str();
			}

		private:
			glm::vec2* m_Vector;
		};

	}
}