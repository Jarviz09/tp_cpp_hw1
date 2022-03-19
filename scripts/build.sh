#!/bin/bash


BUILD_DIR="./build"

rm -rf $BUILD_DIR
mkdir $BUILD_DIR && echo "Creating $BUILD_DIR directory"

cmake $CMAKE_KEYS -B $BUILD_DIR -S .

echo "REBUILD FINISHED!"