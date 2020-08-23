#!/bin/bash

DIR="$( pwd )"
cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1
cd ..

rm -rf build 2>/dev/null
mkdir build out 2>/dev/null

mv $DIR/pongiii.bin build/pongiii.bin

cd build
python3 ../scripts/binpac8x.py -6 -O PONGTHRE pongiii.bin pongiii.86p
mv *.86p ../out
cd ..
rm -rf build
