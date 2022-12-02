PROJ_DIR = path.getabsolute("./../")

solution("Breakout_".. _ACTION)
    location(PROJ_DIR .. "/build/" .. _ACTION)
    language "C++"
    kind "ConsoleApp"

    defines{
        "_CRT_SECURE_NO_WARNINGS"
    }

    configurations{
        "Debug",
        "Release"
    }

    configuration{"Debug"}
    defines{
        "DEBUG",
    }
    flags{
        "Symbols",
        "ExtraWarnings",
    }
    targetsuffix "_d"

    configuration{ "Release"}
    defines{
        "NODEBUG",
    }
    flags{
        "Optimize",
        "OptimizeSize",
        "No64BitChecks",
        "NoPCH",
    }

projects_names = {
    "Breakout",
}

    for i, prj in ipairs(projects_names) do
        project(prj)
            location(PROJ_DIR .. "/build/" .. _ACTION .. "/" .. prj)
            platforms{
                "x32",
                "x64",
                "Native",
            }
            includedirs{
                path.join(PROJ_DIR, "./include/"),
                path.join(PROJ_DIR, "./deps/esat/include/"),
                path.join(PROJ_DIR, "./deps/nfd/include/"),
            }
            files{
                path.join(PROJ_DIR, "./include/oxml/*.h"),
                path.join(PROJ_DIR, "./include/data_base_controller/*.h"),
                path.join(PROJ_DIR, "./src/oxml/*.cc"),
                path.join(PROJ_DIR, "./src/*.cc"),
            }
        
            configuration { "Debug", "x32"}
                targetdir (path.join(PROJ_DIR, "bin/" .. prj .. "/Debug/x32/"))
                objdir(path.join(PROJ_DIR, "./build/" .. _ACTION .. "/" .. prj .. "/Debug"))
                targetsuffix "_d"
            configuration { "Debug", "x64" }
                targetdir (path.join(PROJ_DIR, "bin/" .. prj .. "/Debug/x64/"))
                objdir(path.join(PROJ_DIR, "./build/" .. _ACTION .. "/" .. prj .. "/Debug"))
                targetsuffix "_d"
            configuration { "Release", "x32" }
                targetdir (path.join(PROJ_DIR, "bin/" .. prj .. "/Release/x32/"))
                objdir(path.join(PROJ_DIR, "./build/" .. _ACTION .. "/" .. prj .. "/Release"))
            configuration { "Release", "x64" }
                targetdir (path.join(PROJ_DIR, "bin/" .. prj .. "/Release/x64/"))
                objdir(path.join(PROJ_DIR, "./build/" .. _ACTION .. "/" .. prj .. "/Release"))
        end
    project("Breakout")
        kind "ConsoleApp"
        files {
            path.join(PROJ_DIR, "./src/*.cc"),
          }
      
          includedirs {
            path.join(PROJ_DIR, "./deps/include/"),
          }
        libdirs{
            path.join(PROJ_DIR, "./deps/esat/include/"),
            path.join(PROJ_DIR, "./deps/nfd/include/")
        }
        configuration { "Debug", "x32" }
        links { 
            path.join(PROJ_DIR, "./deps/esat/bin/ESAT_d"),
            path.join(PROJ_DIR, "./deps/nfd/bin/debug/nfd_d"),
            "opengl32",
            "Ole32",
            "gdi32"
        }
        configuration { "Debug", "x64" }
        links { 
            path.join(PROJ_DIR, "./deps/esat/bin/ESAT_d"),
            path.join(PROJ_DIR, "./deps/nfd/bin/debug/nfd_d"),
            "opengl32",
            "Ole32",
            "gdi32"
        }
        configuration { "Release", "x32" }
        links { 
            path.join(PROJ_DIR, "./deps/esat/bin/ESAT"),
            path.join(PROJ_DIR, "./deps/nfd/bin/release/nfd"),
            "opengl32",
            "Ole32",
            "gdi32"
        }
        configuration { "Release", "x64" }
        links { 
            path.join(PROJ_DIR, "./deps/esat/bin/ESAT"),
            path.join(PROJ_DIR, "./deps/nfd/bin/release/nfd"),
            "opengl32",
            "Ole32",
            "gdi32"
        }

        