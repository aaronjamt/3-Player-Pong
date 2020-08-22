#!/bin/bash

cd "$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

rm -rf build log 2>/dev/null
mkdir build out log 2>/dev/null
cp src/pongiii.asm build/pongiii.asm
echo "=============TASM============="
wine tasm -80 -i -b build/pongiii.asm build/pongiii.bin 2>log/wine.err | tee log/wine.log
sed -n -i -e '/org _asm_exec_ram/,// p' build/pongiii.lst
echo "===========BINPAC8X==========="
cd build
python3 ../binpac8x.py -6 -O PONGTHRE pongiii.bin pongiii.86p >../log/binpac8x.log 2| tee ../log/binpac8x.err
mv *.86p ../out
rm -rf build
