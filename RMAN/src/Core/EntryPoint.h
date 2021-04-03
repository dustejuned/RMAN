#pragma once

extern RMAN::Application* RMAN::CreateApplication();

int main(int argv, char** argc) {
	RMAN::Log::Init();
	RMAN_CORE_TRACE("Initialize Engine");
	auto app = RMAN::CreateApplication();
	app->Run();
	delete app;
}