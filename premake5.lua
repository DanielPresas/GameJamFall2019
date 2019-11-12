workspace ("GameJam")
    location("./")

    defines "_CRT_SECURE_NO_WARNINGS"
    configurations { "Debug", "Release" }
	platforms "x64"
	
	includedirs {
		"./include/Cappuccino/include",
		"./include/Externals/fmod/include",
		"./include/Externals/freetype/include",
		"./include/Externals/glad/include",
		"./include/Externals/glfw3/include",
		"./include/Externals/glm/include",
		"./include/Externals/imgui/include",
        "./include/Externals/stb/include",
        "./include"
	}

	filter "platforms:x64"
		system "Windows"
		architecture "x64"
		defines "Win64"
    
    libdirs {
		"./libs"
	}
    
    filter "platforms:x64"
		system "windows"
		architecture "x64"
		defines "Win64"
	
	filter "system:windows"
		systemversion "latest"
		
		defines {
			"GLFW_INCLUDE_NONE",
			"WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
        optimize "on"
		
		filter{}

 project ("GameJam")
	kind "ConsoleApp"
	configuration "windows"
	targetname ("GameJam")

	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("./Build/bin/%{cfg.platform}/%{cfg.buildcfg}")
    objdir    ("./Build/obj/%{cfg.platform}/%{cfg.buildcfg}")

	
	links {
		"capp",
		"Externals"
	}
	
	files {
		"./include/*.h",
		"./include/*.hpp",
		"./src/**.cpp"
	}