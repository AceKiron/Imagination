include "Dependencies.lua"

workspace "Imagination"
    architecture "x64"
    startproject "Imagination"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
    include "vendors/glfw"
    include "vendors/glad"
    include "vendors/imgui"
group ""

group "Core"
    include "Core"
group ""

group "Tools"
    include "Imagination"
group ""