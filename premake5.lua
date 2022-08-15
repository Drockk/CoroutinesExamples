workspace "CoroutinesExamples"
    architecture "x86_64"
    startproject "Example1"

    configurations
    {
        "Debug",
        "Release"
    }

    flags
    {
        "MultiProcessorCompile"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    include "Example_generator_1"