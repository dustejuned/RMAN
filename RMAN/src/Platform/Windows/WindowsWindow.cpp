#include "WindowsWindow.h"

namespace RMAN {
	WindowsWindow::WindowsWindow(const WinProps& props)
	{
		WindowsWindow::Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{

	}

	LRESULT CALLBACK WindowsWindow::WindowCallBackEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		WindowsWindow *self;
		if (WM_NCCREATE == uMsg)
		{
			LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
			self = static_cast<WindowsWindow*>(lpcs->lpCreateParams);
			self->window = hWnd; // save the window handle too!
			SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)((CREATESTRUCT*)lParam)->lpCreateParams);
			return TRUE;
		}
		else {
			self = reinterpret_cast<WindowsWindow*>(
				GetWindowLongPtr(hWnd, GWLP_USERDATA));
		}

		if (self) {
			return self->InstanceCallBackEvent(uMsg, wParam, lParam);
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	LRESULT WindowsWindow::InstanceCallBackEvent(UINT uMsg, WPARAM wParam, LPARAM lParam) {
		switch (uMsg)
		{
		case WM_MOUSEMOVE:
		{
			// Thanks @ForAbby (Discord)
			uint16_t x = lParam & 0xFFFF; uint16_t y = (lParam >> 16) & 0xFFFF;
			int16_t ix = *(int16_t*)&x;   int16_t iy = *(int16_t*)&y;
			//UpdateMouse(ix, iy);
			return 0;
		}
		case WM_SIZE:       //UpdateWindowSize(lParam & 0xFFFF, (lParam >> 16) & 0xFFFF);	
			return 0;
		case WM_MOUSEWHEEL:	//UpdateMouseWheel(GET_WHEEL_DELTA_WPARAM(wParam));           
			return 0;
		case WM_MOUSELEAVE: //UpdateMouseFocus(false);                                    
			return 0;
		case WM_SETFOCUS:	//UpdateKeyFocus(true);                                       
			return 0;
		case WM_KILLFOCUS:	//UpdateKeyFocus(false);                                      
			return 0;
		case WM_KEYDOWN:	//UpdateKeyState(mapKeys[wParam], true);                      
			return 0;
		case WM_KEYUP:		//UpdateKeyState(mapKeys[wParam], false);                     
			return 0;
		case WM_SYSKEYDOWN: //UpdateKeyState(mapKeys[wParam], true);						
			return 0;
		case WM_SYSKEYUP:	//UpdateKeyState(mapKeys[wParam], false);						
			return 0;
		case WM_LBUTTONDOWN://UpdateMouseState(0, true);                                  
			return 0;
		case WM_LBUTTONUP:	//UpdateMouseState(0, false);                                 
			return 0;
		case WM_RBUTTONDOWN://UpdateMouseState(1, true);                                  
			return 0;
		case WM_RBUTTONUP:	//UpdateMouseState(1, false);                                 
			return 0;
		case WM_MBUTTONDOWN://UpdateMouseState(2, true);                                  
			return 0;
		case WM_MBUTTONUP:	//UpdateMouseState(2, false);                                 
			return 0;
		case WM_CLOSE:		//Terminate();                                                
			return 0;
		case WM_DESTROY:	
			PostQuitMessage(0); 
			DestroyWindow(window);
			return 0;
		}
		return DefWindowProc(window, uMsg, wParam, lParam);
	}


	void WindowsWindow::Shutdown() {

	}

	void WindowsWindow::Init(const WinProps& props) {
		winData.Height = props.Height;
		winData.Width = props.Width;

		WNDCLASS wc = { 0 };

		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.hInstance = GetModuleHandle(nullptr);
		wc.lpfnWndProc = WindowCallBackEvent;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.lpszMenuName = nullptr;
		wc.hbrBackground = nullptr;
		wc.lpszClassName = L"RMAN ENGINE";
		RegisterClass(&wc);

		// Define window furniture
		DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		DWORD dwStyle = WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_THICKFRAME;

		//DWORD dwExStyle = 0;
		//DWORD dwStyle = WS_VISIBLE | WS_POPUP;
		//HMONITOR hmon = MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST);
		//MONITORINFO mi = { sizeof(mi) };
		//if (!GetMonitorInfo(hmon, &mi)) return;
		

		/*RECT rWndRect = { 0, 0, mi.rcMonitor.right, mi.rcMonitor.bottom };
		AdjustWindowRectEx(&rWndRect, dwStyle, FALSE, dwExStyle);*/

		RECT winRect = { 0, 0, props.Width, props.Height };
		AdjustWindowRectEx(&winRect, dwStyle, FALSE, dwExStyle);		
		int windowWidth = winRect.right - winRect.left;
		int windowHeight = winRect.bottom - winRect.top;


		window = CreateWindowEx(dwExStyle, L"RMAN ENGINE", L"", dwStyle,
			0, 0, windowWidth, windowHeight, NULL, NULL, GetModuleHandle(nullptr), this);

		if (window)
		{
			//ShowWindow(window, SW_SHOWDEFAULT);
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
		}
	}


}
