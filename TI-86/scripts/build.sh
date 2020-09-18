#!/bin/bash

# exit when any command fails
set -e
# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" command failed with exit code $?."' EXIT


cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1
cd ..

rm -rf build out log
mkdir build out log
cp src/pongiii.asm build/pongiii.asm
echo "=============TASM============="
cd tasm
wine tasm -80 -i -b ../build/pongiii.asm ../build/pongiii.bin ../out/pongiii.lst
cd ..
sed -n -i -e '/org _asm_exec_ram/,// p' out/pongiii.lst
echo "===========BINPAC8X==========="
cd build
python3 ../scripts/binpac8x.py -6 -O PONGTHRE pongiii.bin pongiii.86p
mv *.86p ../out
cd ..
rm -rf build
trap - EXIT DEBUG
