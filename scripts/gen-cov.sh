#!/bin/bash

BUILD_DIRECTORY="build/tests"

pip install gcovr

cd $BUILD_DIRECTORY || (echo "Error. $BUILD_DIRECTORY not created." && exit 1)
ctest
cd ..
EXCLUDING_FILES=".*_deps.*|.*tests.*|project/main.c"
#EXCLUDING_FILES=".*_deps.*"
REPORT_FILE_NAME="coverage.xml"
gcovr -r . -e $EXCLUDING_FILES -o $REPORT_FILE_NAME --xml
lcov -t "./" -o coverage.info -c -d