#!/bin/bash

# Kill netcat and tilp to prevent interference in upload
killall nc >/dev/null 2>&1
killall tilp >/dev/null 2>&1
# Upload
export TI_ADDR="10.6.61.134"    # Change this when the address changes
tilp --calc TI86 --cable GrayLink -p 1 -n out/pongiii.86p
# Run
python3 scripts/asm_pgrm.py
