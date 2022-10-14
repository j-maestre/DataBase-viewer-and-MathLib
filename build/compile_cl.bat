@ECHO OFF

cls

del *.obj *.pdb *.ilk

cl /nologo /Zi /GR- /EHs /W4 /MDd /c -I ..\include -I ..\deps\esat\include  ..\src\*.cc
cl /nologo /Zi /GR- /EHs /W4 /MDd /Fe:../bin/test.exe *.obj ..\deps\esat\bin\ESAT_d.lib opengl32.lib user32.lib gdi32.lib shell32.lib
