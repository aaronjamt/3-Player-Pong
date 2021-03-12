#!/bin/bash

# Set CWD to the script's parent dir (in case we are called from another dir)
cd $( dirname "${BASH_SOURCE[0]}" )
# Setup env so we can access the SDK
source SDK/env.source

# Clean up old files (otherwise changes may not be applied) and build!
cd src
remake -j4 clean all
