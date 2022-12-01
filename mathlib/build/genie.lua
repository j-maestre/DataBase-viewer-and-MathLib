
PROJ_DIR = path.getabsolute("./../")

solution("MathLib_" .. _ACTION)
  location(PROJ_DIR .. "/build/" .. _ACTION)
  language "C++"

  defines {
    "_CRT_SECURE_NO_WARNINGS"
  }

  configurations {
    "Debug",
    "Release"
  }

  configuration { "Debug" }
    defines {
      "DEBUG",
    }
    flags {
      "Symbols",
      "ExtraWarnings",
    }
    targetsuffix "_d"

    configuration { "Release" }
    defines {
      "NDEBUG",
    }
    flags {
      "Optimize",
      "OptimizeSize",
      "No64BitChecks",
      "NoPCH",
    }

  projects_names = {
    "Test",
    "oxml",
    "RayTracing"
  }

  for i, prj in ipairs(projects_names) do
      project(prj)
        location(PROJ_DIR .. "/build/" .. _ACTION .. "/" .. prj)
        platforms {
          "x32",
          "x64",
          "Native",
        }
        includedirs {
          path.join(PROJ_DIR, "./include/"),
        }
        files {
          path.join(PROJ_DIR, "./include/oxml/*.h"),
          path.join(PROJ_DIR, "./src/oxml/*.cc"),
        }

        --libdirs{}

      configuration { "Debug", "x32" }
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

  project("Test")
    kind "ConsoleApp"
    includedirs {
      path.join(PROJ_DIR, "./test/"),
    }
    files {
      path.join(PROJ_DIR, "./test/*.h"),
      path.join(PROJ_DIR, "./test/*.cc"),
      path.join(PROJ_DIR, "./include/oxml/inl/*.inl"),
    }

  project("oxml")
    kind "StaticLib"
    files {
      path.join(PROJ_DIR, "./include/oxml/inl/*.inl"),
    }

  project("RayTracing")
    kind "ConsoleApp"
    files {
      path.join(PROJ_DIR, "./src/*.cc"),
      path.join(PROJ_DIR, "./deps/bin/ImGui/*.cpp"),
    }

    includedirs {
      path.join(PROJ_DIR, "./deps/include/"),
    }

    libdirs {
      path.join(PROJ_DIR, "./deps/bin/SDL/"),
      path.join(PROJ_DIR, "./deps/bin/ImGui/"),
    }

    configuration { "Debug", "x32" }
      links { 
        path.join(PROJ_DIR, "./deps/bin/SDL/x32/Debug/SDL2"),
        path.join(PROJ_DIR, "./deps/bin/SDL/x32/Debug/SDL2main"),
      }
    configuration { "Debug", "x64" }
      links { 
        path.join(PROJ_DIR, "./deps/bin/SDL/x64/Debug/SDL2"),
        path.join(PROJ_DIR, "./deps/bin/SDL/x64/Debug/SDL2main"),
      }
    configuration { "Release", "x32" }
      links { 
        path.join(PROJ_DIR, "./deps/bin/SDL/x32/Release/SDL2"),
        path.join(PROJ_DIR, "./deps/bin/SDL/x32/Release/SDL2main"),
      }
    configuration { "Release", "x64" }
      links { 
        path.join(PROJ_DIR, "./deps/bin/SDL/x64/Release/SDL2"),
        path.join(PROJ_DIR, "./deps/bin/SDL/x64/Release/SDL2main"),
      }