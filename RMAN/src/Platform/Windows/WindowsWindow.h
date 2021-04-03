#pragma once
#include "Core/Core.h"
#include "Core/Window.h"
#include <windows.h>
namespace RMAN {
	class WindowsWindow : public Window
	{
	public:		
		WindowsWindow(const WinProps& props);
		virtual ~WindowsWindow();

		unsigned int GetWidth() const override { return 0; }
		unsigned int GetHeight() const override { return 0; }

		// Window attributes
		void SetEventCallBack(const EventCallBack& callback) override { }

		virtual void* GetNativeWindow() const { return nullptr; }

		static LRESULT CALLBACK WindowCallBackEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	private:
		virtual void Init(const WinProps& props);
		virtual void Shutdown();
		LRESULT InstanceCallBackEvent(UINT uMsg, WPARAM wParam, LPARAM lParam);
		
	private:
		HWND window = nullptr;
		//EventCallBack evCallback;
		WinProps winData;
	};	
}
