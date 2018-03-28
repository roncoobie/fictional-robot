@echo off
REM making sure that i'm using the local env variables to the shell.
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x64

REM telling the machine to look in \misc first for stuff to execute.
set path=H:\fictional-robot\misc;%path%