#!/bin/bash


BUILD_DIR="./build"

rm -rf $BUILD_DIR
mkdir $BUILD_DIR && echo "Creating $BUILD_DIR directory"
cd build
cmake ..
cmake --build .
cd ..

echo "REBUILD FINISHED!"