#include "RMan.h"

class SandboxApp : public RMAN::Application
{
public:
	SandboxApp() {
		
	}
	~SandboxApp(){

	}

private:

};

RMAN::Application* RMAN::CreateApplication() {
	return new SandboxApp();
}