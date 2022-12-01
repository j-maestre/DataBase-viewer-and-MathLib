@ECHO OFF

cls

del *.obj *.pdb *.ilk

cl /nologo /Zi /GR- /EHs /W4 /MDd /c -I ..\include -I ..\deps\include\ ..\deps\bin\ImGui\*.cpp
cl /nologo /Zi /GR- /EHs /W4 /MDd /c -I ..\include -I ..\deps\include\ ..\src\oxml\*.cc
cl /nologo /Zi /GR- /EHs /W4 /MDd /c -I ..\include -I ..\deps\include\ ..\src\*.cc
cl /nologo /Zi /GR- /EHs /W4 /MDd /Fe:test.exe *.obj /link /SUBSYSTEM:CONSOLE ..\deps\bin\SDL\x32\Debug\SDL2.lib ..\deps\bin\SDL\x32\Debug\SDL2main.lib shell32.lib opengl32.lib user32.lib