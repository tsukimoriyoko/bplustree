#!/bin/sh
rm -rf build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Frequency ..
make
./bin/bplustree_frequency