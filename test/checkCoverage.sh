#!/bin/bash

mkdir build
cd build
cmake ..
make
cd ..
./build/testing

DIR=`tree -dfi | grep "src/DB"`

lcov --capture --directory $DIR --output-file build/coverage.info
genhtml build/coverage.info --output-directory coverage


