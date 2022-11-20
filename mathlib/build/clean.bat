@ECHO OFF

del *.obj *.pdb *.ilk *.exe

IF EXIST .\vs2019 rmdir /s /q .\vs2019
IF EXIST ..\bin\PR00_Test rmdir /s /q ..\bin\PR00_Test
IF EXIST ..\bin\PR01_StaticLibrary rmdir /s /q ..\bin\PR01_StaticLibrary