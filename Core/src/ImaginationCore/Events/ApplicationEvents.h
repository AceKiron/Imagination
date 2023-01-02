#pragma once

#include <glm/glm.hpp>

#include "Event.h"

namespace Imagination {
	namespace Events {

		class WindowCloseEvent : public Event {
		public:
			WindowCloseEvent() : Event(EventType::WindowClose) {}

			virtual std::string ToString() const override {
				return "WindowCloseEvent";
			}
		};

		class WindowResizeEvent : public Event {
		public:
			WindowResizeEvent(uint32_t width, uint32_t height) : Event(EventType::WindowResize), m_Vector(new glm::vec2(width, height)) {}

			inline glm::vec2* GetVector() const { return m_Vector; }

			virtual std::string ToString() const override {
				std::stringstream ss;
				ss << "WindowResizeEvent: " << m_Vector->x << ", " << m_Vector->y;
				return ss.str();
			}

		private:
			glm::vec2* m_Vector;
		};

		class WindowFocusEvent : public Event {
		public:
			WindowFocusEvent() : Event(EventType::WindowFocus) {}

			virtual std::string ToString() const override {
				return "WindowFocusEvent";
			}
		};

		class WindowLostFocusEvent : public Event {
		public:
			WindowLostFocusEvent() : Event(EventType::WindowLostFocus) {}

			virtual std::string ToString() const override {
				return "WindowLostFocusEvent";
			}
		};

		class WindowMovedEvent : public Event {
		public:
			WindowMovedEvent(uint32_t xpos, uint32_t ypos) : Event(EventType::WindowMoved), m_Vector(new glm::vec2(xpos, ypos)) {}

			inline glm::vec2* GetVector() const { return m_Vector; }

			virtual std::string ToString() const override {
				std::stringstream ss;
				ss << "WindowMovedEvent: " << m_Vector->x << ", " << m_Vector->y;
				return ss.str();
			}

		private:
			glm::vec2* m_Vector;
		};

	}
}