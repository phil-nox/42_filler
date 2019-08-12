#!/bin/bash
export NAME=boa.filler
export PATH_H=./header
make re
export NAME=boa_debug.filler
export PATH_H=./header_debug
make re
rm -f test_debug
touch test_debug