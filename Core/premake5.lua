project "Core"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "imaginationpch.h"
    pchsource "Core/src/imaginationpch.cpp"

    files {
        "src/**.h",
        "src/**.cpp"
    }
    
    includedirs {
        "%{wks.location}/Core/src",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.ImGui}"
    }

    links {
        "GLFW",
        "Glad",
        "ImGui"
    }

    filter "system:windows"
        systemversion "latest"
        defines "IMAGINATION_PLATFORM_WINDOWS"

    filter "configurations:Debug"
        defines "IMAGINATION_CONFIGURATION_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "IMAGINATION_CONFIGURATION_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "IMAGINATION_CONFIGURATION_DIST"
        runtime "Release"
        optimize "on"