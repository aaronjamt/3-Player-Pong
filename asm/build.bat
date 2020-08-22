@echo off

cd asm

rmdir /S /Q build log > nul
mkdir build out log > nul
copy /Y src/pongiii.asm build/pongiii.asm
echo =============TASM=============
tasm -80 -i -b build/pongiii.asm build/pongiii.bin 2>log/wine.err >log/wine.log
type log/wine.log
echo ===========BINPAC8X===========
cd build
python3 ../binpac8x.py -6 -O PONGTHRE pongiii.bin pongiii.86p >../log/binpac8x.log 2>../log/binpac8x.err
type ../log/binpac8x.err
move *.86p ../out > nul
rmdir /S /Q build > nul
