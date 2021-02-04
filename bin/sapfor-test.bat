@echo off
set pts=%userprofile%\home\workspace\pts\bin\pts
set sapfor_test_install_prefix=%~dp0..

if "%sapfor_test_install_prefix%" == "" (echo variable "sapfor_test_install_prefix" is not set & goto :eof)
if "%pts%" == "" (echo variable "pts" is not set & goto :eof)

set lib=%sapfor_test_install_prefix%\sys
set sys_tasks=%sapfor_test_install_prefix%\sys\tasks
call %pts% -I %lib% -T %sys_tasks% --failed=f -s --total-time %*
