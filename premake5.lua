workspace "Hashtag4"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hashtag4"
	location "Hashtag4"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"H4_PLATFORM_WINDOWS",
			"H4_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/TheIsland")
		}

	filter "configurations:Debug"
		defines "H4_DEBUG"
		symbols "On"

	
	filter "configurations:Release"
		defines "H4_RELEASE"
		symbols "On"

	
	filter "configurations:Dist"
		defines "H4_DIST"
		symbols "On"

project "TheIsland"
	location "TheIsland"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp",
	}

	includedirs
	{
		"Hashtag4/vendor/spdlog/include",
		"Hashtag4/source"
	}

	links
	{
		"Hashtag4"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"H4_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
	defines "H4_DEBUG"
	symbols "On"

	
	filter "configurations:Release"
		defines "H4_RELEASE"
		symbols "On"

	
	filter "configurations:Dist"
		defines "H4_DIST"
		symbols "On"