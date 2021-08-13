workspace "Poke"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	startproject "PokeNeedle"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Poke/vendor/GLFW/include"
IncludeDir["Glad"] = "Poke/vendor/Glad/include"
IncludeDir["ImGui"] = "Poke/vendor/imgui"
IncludeDir["glm"] = "Poke/vendor/glm"
IncludeDir["stb_image"] = "Poke/vendor/stb_image"
IncludeDir["entt"] = "Poke/vendor/entt/include"

group "Dependencies"
	include "Poke/vendor/GLFW"
	include "Poke/vendor/Glad"
	include "Poke/vendor/imgui"

project "Poke"
	location "Poke"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/"..outputdir.."%{prj.name}")
	objdir("bin-int/"..outputdir.."%{prj.name}")

	pchheader "pkpch.h"
	pchsource "Poke/src/pkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"

	}

	defines
	{
		" _CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}"
	}
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		


	filter "configurations:Debug"
		defines "PK_DEBUG"
		runtime "Debug"		
		symbols "on"

	filter "configurations:Release"
		defines "PK_RELEASE"
		runtime "Release"		
		optimize "on"

	filter "configurations:Dist"
		defines "PK_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
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
		"Poke/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	
	filter "system:windows"
		
		staticruntime "On"
		systemversion "latest"

	
	filter "configurations:Debug"
		defines "PK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PK_DIST"
		runtime "Release"
		optimize "on"

project "PokeNeedle"
	location "PokeNeedle"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
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
		"Poke/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
		
	}

	
	filter "system:windows"
		
		staticruntime "On"
		systemversion "latest"

	
	filter "configurations:Debug"
		defines "PK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PK_DIST"
		runtime "Release"
		optimize "on"