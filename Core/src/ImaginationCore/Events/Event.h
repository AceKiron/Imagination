#pragma once

#include "../Core.h"

namespace Imagination {
	namespace Events {

		enum EventType {
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			KeyPressed, KeyReleased, KeyTyped,
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
		};

		class Event {
		public:
			inline const bool& IsHandled() const { return m_Handled; }
			inline void MarkHandled() { m_Handled = true; }

			inline const EventType& GetType() const { return m_Type; }
			
			virtual std::string ToString() const = 0;

		protected:
			Event(EventType type) : m_Handled(false), m_Type(type) {}
			~Event() {}

		private:
			bool m_Handled;
			EventType m_Type;
		};

	}
}