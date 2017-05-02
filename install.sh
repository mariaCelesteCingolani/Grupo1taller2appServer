#!/bin/bash

# Install libmongoc

sudo apt-get install pkg-config libssl-dev libsasl2-dev
wget https://github.com/mongodb/mongo-c-driver/releases/download/1.6.2/mongo-c-driver-1.6.2.tar.gz && tar xzf mongo-c-driver-1.6.2.tar.gz && cd mongo-c-driver-1.6.2 && ./configure --disable-automatic-init-and-cleanup && make && sudo make install && cd ..

# Install libmongocxx

git clone https://github.com/mongodb/mongo-cxx-driver.git --branch releases/stable --depth 1 && cd mongo-cxx-driver/build && cmake -DCMAKE_BUILD_TYPE=Release -DBSONCXX_POLY_USE_MNMLSTC=1 -DCMAKE_INSTALL_PREFIX=/usr/local .. && sudo make EP_mnmlstc_core && make && sudo make install && cd ../..

# Google Test

git clone https://github.com/google/googletest.git && cd googletest && mkdir build && cd build && cmake -DBUILD_SHARED_LIBS=ON .. && make && cd ../googletest && sudo cp -a include/gtest /usr/include && cmake -DBUILD_SHARED_LIBS=ON . && make && sudo cp -a libgtest_main.so libgtest.so /usr/lib/ && sudo ldconfig && cd ../..

