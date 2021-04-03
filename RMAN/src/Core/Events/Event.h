#pragma once
#include "Core/Core.h"
namespace RMAN {
	enum class EventType {
		None = 0,
		KeyPressed, KeyReleased, KeyTyped, MousePressed, MouseReleased, MouseMoved, MouseScrolled
	};
	enum EventCategory
	{
		None = 0,
		EvCategoryApplication = SHIFTRIGHT(0),
		EvCategoryInput = SHIFTRIGHT(1),
		EvCategoryKeyboard = SHIFTRIGHT(2),
		EvCategoryMouse = SHIFTRIGHT(3),
		EvCategoryMouseButton = SHIFTRIGHT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::type;}\
							   virtual EventType GetEventType() const override {return GetStaticType();}\
							   virtual const char* GetName() const override{return #type;}	

#define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategory() const override{return category;}



	class Event
	{
	public:
		~Event() = default;

		bool isHandled = false;
		virtual const char* GetName() const = 0;
		virtual EventType GetEventType() const = 0;
		virtual int GetEventCategory() const = 0;
		virtual std::string ToString() const { return GetName(); }
	};

	class EventDispatcher {
		EventDispatcher(Event& ev) : _event(ev)
		{

		}
		template<typename T, typename F>
		bool DipatchEvent(const F& func) {
			if (_event.GetEventType() == T::GetStaticType())
			{
				_event.isHandled |= func(static_cast<T&>(_event));
				return true;
			}
			return false;
		}
	private:
		Event& _event;
	};


}



