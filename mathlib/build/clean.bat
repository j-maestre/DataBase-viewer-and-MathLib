@ECHO OFF

del *.obj *.pdb *.ilk *.exe

IF EXIST .\vs2019 rmdir /s /q .\vs2019
IF EXIST ..\bin\Test rmdir /s /q ..\bin\Test
IF EXIST ..\bin\oxml rmdir /s /q ..\bin\oxml

pause