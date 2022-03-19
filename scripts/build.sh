#!/bin/bash

#BUILD_DIR="./build"
#LOG_FILE="./tmp/build.log"
#TMP_DIR="./tmp"
#
#rm -rf $BUILD_DIR
#mkdir -p $TMP_DIR
#touch $LOG_FILE
#mkdir $BUILD_DIR && echo "Creating $BUILD_DIR directory"
#cd build
#cmake ..
#cmake --build .
#cd ..


BUILD_DIR="./build"

rm -rf $BUILD_DIR
mkdir $BUILD_DIR && echo "Creating $BUILD_DIR directory"

cmake $CMAKE_KEYS -B $BUILD_DIR -S .

echo "REBUILD FINISHED!"