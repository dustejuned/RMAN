#include "Application.h"

namespace RMAN {
	Application::Application() {
		app_window = Window::Create(WinProps("Hazel Engine"));
		//app_window->SetEventCallBack(Application::OnEvent);
	}	

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {

	}

	void Application::Run() {
		while (true);
	}
}
