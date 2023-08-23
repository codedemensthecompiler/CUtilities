#!/bin/bash
echo "\033[0;92m Compiling devbuild of\033[1;37m CUtilities\033[0;92m using\033[1;37m GNU GCC (g++)\033[0;92m with predefined config.:"
echo "\033[0;92m and subsequently devbuilds of\033[1;37m configset\033[0;92m using\033[1;37m GNU GCC (g++)\033[0;92m with predefined config.:"
echo "------------------------------------------"
echo ""

OUTPUT='bin'

mkdir -p ./$OUTPUT

echo "\033[0;92m CUtilities (g++).:"
g++ impl/cutilities.cpp impl/common.cpp -I impl/ -o $OUTPUT/cutilities

echo "\033[0;92m configset (g++).:"
g++ impl/configset.cpp impl/common.cpp -I impl/ -o $OUTPUT/configset

echo "\033[0;92m encrypt (g++).:"
g++ impl/encrypt.cpp impl/common.cpp -I impl/ -o $OUTPUT/encrypt
