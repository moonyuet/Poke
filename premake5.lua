workspace "Poke"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Poke/vendor/GLFW/include"
IncludeDir["Glad"] = "Poke/vendor/Glad/include"
IncludeDir["ImGui"] = "Poke/vendor/imgui"
IncludeDir["glm"] = "Poke/vendor/glm"

include "Poke/vendor/GLFW"
include "Poke/vendor/Glad"
include "Poke/vendor/imgui"

project "Poke"
	location "Poke"
	kind "SharedLib"
	language "C++"

	targetdir("bin/"..outputdir.."%{prj.name}")
	objdir("bin-int/"..outputdir.."%{prj.name}")

	pchheader "pkpch.h"
	pchsource "Poke/src/pkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PK_PLATFORM_WINDOWS",
			"PK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

			
		postbuildcommands{
			
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "Sandbox/\"")
		}

	
		


	filter "configurations:Debug"
		defines "PK_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PK_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	targetdir("bin/"..outputdir.."%{prj.name}")
	objdir("bin-int/"..outputdir.."%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	links
	{
		"Poke"
	}
	includedirs
	{
		"Poke/vendor/spdlog/include",
		"Poke/src",
		"%{IncludeDir.glm}"
	}

	

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PK_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "PK_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PK_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PK_DIST"
		buildoptions "/MD"
		optimize "On"