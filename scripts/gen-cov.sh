#!/bin/bash

BUILD_DIRECTORY="build/tests"

pip install gcovr

cd $BUILD_DIRECTORY || (echo "Error. $BUILD_DIRECTORY not created." && exit 1)
ctest
cd ../..
EXCLUDING_FILES=".*_deps.*|.*tests.*|project/main.c"
##EXCLUDING_FILES=".*_deps.*"
#REPORT_FILE_NAME="coverage.xml"
g++ -I project/include tests/tests.cpp project/src/utils.c project/src/food.c -lgtest -lpthread -o test_check_1
./test_check_1
gcc -I ./project/include project/main.c project/src/*.c
./a.out ration.txt
gcovr -r . -e $EXCLUDING_FILES