#!/bin/bash

cd $( dirname "${BASH_SOURCE[0]}" )
source SDK/env.source

rm -rf out >/dev/null 2>&1
mkdir out

cd src
remake -j4
