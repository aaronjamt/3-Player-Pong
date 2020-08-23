echo on

cd ..
rmdir /S /Q build
mkdir build
dir
dir src
dir build
copy src/pongiii.asm build/pongiii.asm
cd tasm
tasm -80 -i -b ../build/pongiii.asm ../build/pongiii.bin
