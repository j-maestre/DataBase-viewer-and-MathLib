@ECHO OFF

cls

del *.obj *.pdb *.ilk
del ../bin/*.pdb
del ../bin/*.ilk
del ../bin/*.exe

cl /nologo /Zi /GR- /EHs /W4 /MDd /c -I ..\include -I ..\deps\esat\include  ..\src\*.cc
cl /nologo /Zi /GR- /EHs /W4 /MDd /Fe:../bin/test.exe *.obj ..\deps\esat\bin\ESAT_d.lib opengl32.lib user32.lib gdi32.lib shell32.lib
