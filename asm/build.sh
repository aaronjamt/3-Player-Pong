#!/bin/bash

rm -rf build 2>/dev/null
mkdir build out 2>/dev/null
cp src/pongiii.asm build/pongiii.asm
echo "=============TASM============="
wine tasm -80 -i -b build/pongiii.asm build/pongiii.bin
sed -n -e '/org _asm_exec_ram/,// p' build/pongiii.lst > build/pongiii.lst.tmp
mv build/pongiii.lst.tmp build/pongiii.lst
#echo "===========BINPAC8X==========="
cd build
python3 ../binpac8x.py -6 -O PONGTHRE pongiii.bin pongiii.86p >/dev/null
mv *.86p ../out
rm -rf build
