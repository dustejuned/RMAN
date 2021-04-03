#pragma once
#include <memory>
#include <string>
#include <functional>
#ifdef RMAN_PLATFORM_WINDOWS
	#ifdef RMAN_BUILD_DLL
		#define RMAN_API __declspec(dllexport)
	#else
		#define RMAN_API __declspec(dllimport)
	#endif // RMAN_BUILD_DLL	
#else
	#error RMAN only supports windows
#endif	
#define SHIFTRIGHT(x) (1 << x)
