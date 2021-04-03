workspace "RMAN"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "RMAN"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RMAN_PLATFORM_WINDOWS",
			"RMAN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RMAN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RMAN_RELEASE"
		optimize "On"

project "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"RMAN/src",
		"vendor/spdlog/include"
	}

	links
	{
		"RMAN"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RMAN_PLATFORM_WINDOWS"			
		}		

	filter "configurations:Debug"
		defines "RMAN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RMAN_RELEASE"
		optimize "On"

