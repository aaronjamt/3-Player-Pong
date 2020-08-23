@echo off

cd ..

rmdir /S /Q build 2>nul
mkdir build 2>nul
copy src/pongiii.asm build/pongiii.asm
cd tasm
tasm -80 -i -b ../build/pongiii.asm ../build/pongiii.bin
