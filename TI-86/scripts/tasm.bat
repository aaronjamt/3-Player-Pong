@echo off

cd ..
rmdir /S /Q build >nul 2>nul
mkdir build >nul 2>nul
copy src\pongiii.asm build\pongiii.asm >nul 2>nul

set TASMTABS=%CD%\tasm
tasm\tasm -80 -i -b build\pongiii.asm build\pongiii.bin
