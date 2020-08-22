@echo off

cd asm

rmdir /S /Q build out 2>nul
mkdir build out 2>nul
copy src/pongiii.asm build/pongiii.asm
echo =============TASM=============
tasm -80 -i -b build/pongiii.asm build/pongiii.bin
echo ===========BINPAC8X===========
cd build
python3 ../binpac8x.py -6 -O PONGTHRE pongiii.bin pongiii.86p
move *.86p ../out > nul
rmdir /S /Q build > nul
