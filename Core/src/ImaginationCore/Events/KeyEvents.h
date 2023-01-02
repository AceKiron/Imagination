#pragma once

#include "Event.h"

namespace Imagination {
	namespace Events {

		class KeyEvent : public Event {
		public:
			inline int GetKeyCode() const { return m_KeyCode; }

		protected:
			KeyEvent(EventType eventType, int keyCode) : Event(eventType), m_KeyCode(keyCode) {}

			int m_KeyCode;
		};

		class KeyPressedEvent : public KeyEvent {
		public:
			KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(EventType::KeyPressed, keyCode), m_RepeatCount(repeatCount) {}

			inline int GetRepeatCount() const { return m_RepeatCount; }

			virtual std::string ToString() const override {
				std::stringstream ss;
				ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
				return ss.str();
			}

		private:
			int m_RepeatCount;
		};

		class KeyReleasedEvent : public KeyEvent {
		public:
			KeyReleasedEvent(int keyCode) : KeyEvent(EventType::KeyReleased, keyCode) {}

			virtual std::string ToString() const override {
				std::stringstream ss;
				ss << "KeyReleasedEvent: " << m_KeyCode;
				return ss.str();
			}
		};

		class KeyTypedEvent : public KeyEvent {
		public:
			KeyTypedEvent(int keyCode) : KeyEvent(EventType::KeyTyped, keyCode) {}

			virtual std::string ToString() const override {
				std::stringstream ss;
				ss << "KeyTypedEvent: " << m_KeyCode;
				return ss.str();
			}
		};

	}
}