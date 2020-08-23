#!/bin/bash

# Kill netcat and tilp to prevent interference in upload
killall nc >/dev/null 2>&1
killall tilp >/dev/null 2>&1
# Upload
tilp --calc TI86 --cable GrayLink -p 1 -n out/pongiii.86p
