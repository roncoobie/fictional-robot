@echo off
rem make sure the directory "build" exists for putting in our debug stuff
mkdir ..\build
rem push the directory so that we're operating up there instead of the current one.
pushd ..\build
rem compile and stick the executable in the "build" directory.
cl -Zi ..\fictional-robot\code\win32_handmade.cpp user32.lib
rem pop back into the current directory.
popd