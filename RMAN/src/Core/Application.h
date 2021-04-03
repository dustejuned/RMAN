#pragma once
#include "Core.h"
#include "Window.h"
namespace RMAN {
	class RMAN_API Application
	{
	public:

		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& ev);
	private:
		std::unique_ptr<Window> app_window;
	};

	Application* CreateApplication();
}


