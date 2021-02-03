@echo off
set sapfor_test_install_prefix=%userprofile%\home\workspace\t
set tsar=%userprofile%\home\workspace\sapfor\build\analyzers\tsar\tools\tsar\Debug\tsar.exe
set include=%userprofile%\home\workspace\sapfor\build\llvm-build\Debug\lib\clang\11.1.0\include
set clang=
set pts=%userprofile%\home\workspace\pts\bin\pts

if "%sapfor_test_install_prefix%" == "" (echo variable "sapfor_test_install_prefix" is not set & goto :eof)
if "%tsar%" == "" (echo variable "tsar" is not set & goto :eof)
if "%pts%" == "" (echo variable "pts" is not set & goto :eof)

set lib=%sapfor_test_install_prefix%\sys
set sys_tasks=%sapfor_test_install_prefix%\sys\tasks
set setenv=setenv:tsar='%tsar%',platform=win,include='%include%',clang='%clang%'
call %pts% -I %lib% -T %sys_tasks% --failed=f -s --total-time %setenv% %*
