#!/bin/bash
pkill tilem >/dev/null 2>&1
killall tilem >/dev/null 2>&1
python3 debugger.py & > /dev/null 2>&1 &
tilem2 -p asm_prog.macro -d out/pongiii.86p
