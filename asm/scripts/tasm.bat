@echo off

set TASMTABS=%CD%

cd ..
rmdir /S /Q build
mkdir build
copy src\pongiii.asm build\pongiii.asm

tasm\tasm -80 -i -b build\pongiii.asm build\pongiii.bin
