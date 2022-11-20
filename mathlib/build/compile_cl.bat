@ECHO OFF

del *.obj *.pdb *.ilk *.exe

cl /nologo /Zi /GR- /EHs /W3 /MDd /D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\test\include /c ..\src\*.cc ..\test\*.cc
cl /nologo /Zi /GR- /EHs /W3 /MDd /D_CRT_SECURE_NO_WARNINGS /Fe:unit_test_d.exe *.obj

