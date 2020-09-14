#!/bin/bash

ROOT="`pwd`"
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
PREFIX="$ROOT/mipsel-unknown-elf"
PATHS="$PREFIX/bin"

# If `apt` is available, set $apt to `apt`.
# Otherwise, fallback to `apt-get`.
apt="`apt help >/dev/null 2>&1 && echo apt || echo apt-get`"

# Make sure required packages are installed
sudo $apt install -y tar gcc make remake perl wget git texinfo lib{mpfr,isl,gmp,mpc,tinyxml2}-dev build-essential

# libmpfr4 is required, however some systems (notably Ubuntu 18.04) have removed it.
# This hack allows libmpfr6 (which is compatible enough) to act in place.
sudo $apt install -y libmpfr4 || sudo ln -s /usr/lib/x86_64-linux-gnu/libmpfr.so.6 /usr/lib/x86_64-linux-gnu/libmpfr.so.4

compile_toolchain() {
    mkdir build $PREFIX
    cd build
    mkdir binutils-build gcc-build

    echo "------------COMPILING BINUTILS-----------"
    echo "Downloading binutils-2.31.tar.gz..."
    wget "ftp://ftp.gnu.org/gnu/binutils/binutils-2.31.tar.gz"
    echo "Extracting binutils-2.31.tar.gz..."
    tar -xzf binutils-2.31.tar.gz
    rm binutils-2.31.tar.gz

    cd binutils-build
    echo "Configuring binutils (prefix=$PREFIX, target=mipsel-unknown-elf)..."
    ../binutils-2.31/configure --prefix="$PREFIX" \
        --target=mipsel-unknown-elf --with-float=soft
    echo "Compiling binutils..."
    remake -j4
    echo "Installing binutils to $PREFIX..."
    remake -j4 install-strip
    cd ..
    rm -rf binutils-build binutils-2.31
    echo "------------BINUTILS COMPILED-----------"

    sleep 2

    echo "------------COMPILING GCC------------"
    echo "Downloading gcc-7.4.0.tar.gz..."
    wget "ftp://ftp.gnu.org/gnu/gcc/gcc-7.4.0/gcc-7.4.0.tar.gz"
    echo "Extracting gcc-7.4.0.tar.gz..."
    tar -xzf gcc-7.4.0.tar.gz
    rm gcc-7.4.0.tar.gz

    cd gcc-build
    echo "Configuring gcc (prefix=$PREFIX, target=mipsel-unknown-elf)..."
    ../gcc-7.4.0/configure --disable-nls --disable-libada --disable-libssp \
        --disable-libquadmath --disable-libstdc++-v3 --target=mipsel-unknown-elf \
        --prefix=$PREFIX --with-float=soft \
        --enable-languages=c,c++ --with-gnu-as --with-gnu-ld
    echo "Compiling gcc..."
    remake -j4
    echo "Installing gcc to $PREFIX..."
    remake -j4 install-strip
    cd ..
    rm -rf gcc-build gcc-7.4.0
    echo "------------GCC COMPILED-----------"
    cd "$ROOT"
    rm -rf build
    echo "Toolchain compiled, patching elf32elmip.x..."
    patch -s -u mipsel-unknown-elf/mipsel-unknown-elf/lib/ldscripts/elf32elmip.x << EOF
@@ -94,6 +94,24 @@
     /* .gnu.warning sections are handled specially by elf32.em.  */
     *(.gnu.warning)
     *(.mips16.fn.*) *(.mips16.call.*)
+    
+    __CTOR_LIST__ = .;
+    ___CTOR_LIST__ = .;
+    LONG (((__CTOR_END__ - __CTOR_LIST__) / 4) - 2)
+    KEEP (*(SORT (.ctors.*)))
+    KEEP (*(.ctors))
+    LONG (0x00000000)
+    __CTOR_END__ = .;
+    . = ALIGN (0x10);
+
+    __DTOR_LIST__ = .;
+    ___DTOR_LIST__ = .;
+    LONG (((__DTOR_END__ - __DTOR_LIST__) / 4) - 2)
+    KEEP (*(SORT (.dtors.*)))
+    KEEP (*(.dtors))
+    LONG (0x00000000)
+    __DTOR_END__ = .;
+    . = ALIGN (0x10);
   }
   .fini           :
   {
EOF
    echo "Toolchain compiled and ready to go!"
}

compile_or_locate_toolchain() {
    read -p "Do you want to compile the toolchain? [Y/n] "
    if [ "$REPLY" = "n" ]; then
        read -p "Where is your mipsel-unknown-elf toolchain located (AKA prefix)? [$PREFIX] "
        if [ "$REPLY" = "" ]; then
            REPLY="$PREFIX"
        fi
        if [ -d "$REPLY" ]; then
            PREFIX="$REPLY"
        else
            echo "'$REPLY' is not a directory." >&2
            exit 1
        fi
        PATHS="$PREFIX/bin"
    else
        compile_toolchain
    fi
}

if [ "`uname -m`" = "x86_64" ]; then
    read -p "Precompiled toolchain available. Do you want to use it? [Y/n] "
    if [ "$REPLY" = "n" ]; then
        compile_or_locate_toolchain
    else
        cd "$ROOT"
        tar -xzf "$DIR/toolchains/mipsel-unknown-elf_`uname -m`.tar.gz"
    fi
fi

cd "$ROOT"

if [ ! -d "PSn00bSDK" ]; then
    echo "Downloading PSn00bSDK..."
    git clone "https://github.com/Lameguy64/PSn00bSDK"
fi

if [ ! -d "PSn00bSDK/tools/bin" ]; then
    echo "Compiling PSn00bSDK tools..."
    cd PSn00bSDK/tools
    remake -j4
    remake -j4 install
    PATHS="$PATHS:$PWD/bin"
fi

cd "$ROOT"

cd PSn00bSDK/libpsn00b
echo "Patching libpsn00b common.mk to set PREFIX..."
patch -s -u common.mk << EOF
@@ -17,7 +17,7 @@
 
 else						# For Linux/BSDs
 
-GCC_BASE	= /usr/local/mipsel-unknown-elf
+GCC_BASE	= $PREFIX
 
 endif
 
EOF
echo "Compiling libpsn00b..."
PATH=$PATH:$PREFIX/bin remake -j4

cd "$ROOT/PSn00bSDK/examples"
patch -s -u sdk-common.mk << EOF
@@ -24,7 +24,7 @@
 
 else						# For Linux/BSDs
 
-GCC_BASE	= /usr/local/mipsel-unknown-elf
+GCC_BASE	= $PREFIX
 
 endif
 
EOF

cd "$ROOT"

echo "Creating env.source..."
echo "export PATH=\$PATH:$PATHS:$DIR/scripts" > env.source
echo "export GCC_BASE=$PREFIX" >> env.source
echo "export LIBPSN00B=$ROOT/PSn00bSDK/libpsn00b" >> env.source

echo "Installed! Run 'source $ROOT/env.source' or 'source env.source' when in '$ROOT' to apply environment variables!"
