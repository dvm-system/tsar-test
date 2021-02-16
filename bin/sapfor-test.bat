@echo off
::=== Variables set by CMake ===
set perl=perl
set lib=%~dp0../sys/lib
::==============================
call "%perl%" -I "%lib%" "%~dp0/sapfor-test.pl" %*
