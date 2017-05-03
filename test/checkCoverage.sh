#!/bin/bash

mkdir build
cd build
cmake ..
make
cd ..
sudo service mongod start
./build/testing
sudo service mongod stop

DIR=`tree -dfi | grep "src/DB"`

lcov --capture --directory $DIR --output-file build/coverage.info
genhtml build/coverage.info --output-directory coverage


