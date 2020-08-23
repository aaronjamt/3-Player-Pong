@echo off

cd ..
rmdir /S /Q build
mkdir build
copy src\pongiii.asm build\pongiii.asm

set TASMTABS=%CD%\tasm
tasm\tasm -80 -i -b build\pongiii.asm build\pongiii.bin
