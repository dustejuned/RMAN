#include "Event.h"
#include "KeyCodes.h"

namespace RMAN {
	class KeyEvent: public Event
	{
	public:
		KeyCode GetKeyCode() const { return keyCode; }
		EVENT_CLASS_CATEGORY(EvCategoryKeyboard | EvCategoryInput);
		
	protected:
		KeyEvent(const KeyCode code) : keyCode(code) {};
		KeyCode keyCode;

	};	

	class KeyPressedEvent: public KeyEvent
	{
	public:
		KeyPressedEvent(const KeyCode code, const uint16_t repeatCount) : KeyEvent(code), _repeateCount(repeatCount)  {};		


		EVENT_CLASS_TYPE(KeyPressed);
	private:
		uint16_t _repeateCount;
	};	
}