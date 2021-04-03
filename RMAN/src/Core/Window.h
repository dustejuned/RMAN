#pragma once
#include "Core/Core.h"
#include "Core/Events/Event.h"

namespace RMAN {
	struct WinProps {
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WinProps(const std::string& title = "RMAN Engine", uint32_t width = 1600, uint32_t height = 900) : Title(title), Width(width), Height(height)
		{
				
		}
	};
	class Window
	{
	public:
		using EventCallBack = std::function<void(Event&)>;
		virtual ~Window() = default;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual void SetEventCallBack(const EventCallBack& callback) = 0;
		virtual void* GetNativeWindow() const = 0;
		static std::unique_ptr<Window> Create(const WinProps& props = WinProps());
	};
}
