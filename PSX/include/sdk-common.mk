# Toolchain prefix
PREFIX		= mipsel-unknown-elf-

# Include directories
INCLUDE	 	= -I$(LIBPSN00B)/include

# Library directories, last entry must point toolchain libraries
LIBDIRS		= -L$(LIBPSN00B)

ifndef GCC_VERSION

GCC_VERSION	= 7.4.0

endif

ifndef GCC_BASE

ifeq "$(OS)" "Windows_NT"	# For Windows

GCC_BASE	= /c/mipsel-unknown-elf

else						# For Linux/BSDs

GCC_BASE	= /usr/local/mipsel-unknown-elf

endif

endif

LIBDIRS 	+= -L$(GCC_BASE)/lib/gcc/mipsel-unknown-elf/$(GCC_VERSION)
INCLUDE	 	+= -I$(GCC_BASE)/lib/gcc/mipsel-unknown-elf/$(GCC_VERSION)/include
