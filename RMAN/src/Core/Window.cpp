#include "Window.h"
#include "Core/Core.h"
#include "Platform/Windows/WindowsWindow.h"
namespace RMAN {
	std::unique_ptr<Window> Window::Create(const WinProps& props) {
		return std::make_unique<WindowsWindow>(props);
	}
}