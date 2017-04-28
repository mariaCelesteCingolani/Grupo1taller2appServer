# Set the base image to Ubuntu
FROM ubuntu:16.04

# Install required packages
RUN apt-get update && apt-get install -y \
  cmake \
  git \
  g++ \
  make \
  wget \
  curl \
  vim \
  pkg-config \
  libssl-dev \
  libsasl2-dev 

# Install libmongoc

RUN cd home && wget https://github.com/mongodb/mongo-c-driver/releases/download/1.6.2/mongo-c-driver-1.6.2.tar.gz && tar xzf mongo-c-driver-1.6.2.tar.gz && cd mongo-c-driver-1.6.2 && ./configure --disable-automatic-init-and-cleanup && make && make install && cd ..

# Install libmongocxx

RUN git clone https://github.com/mongodb/mongo-cxx-driver.git --branch releases/stable --depth 1 && cd mongo-cxx-driver/build && cmake -DCMAKE_BUILD_TYPE=Release -DBSONCXX_POLY_USE_MNMLSTC=1 -DCMAKE_INSTALL_PREFIX=/usr/local .. && make EP_mnmlstc_core && make && make install && cd .. && cd ..

# Copy src from git

RUN git clone https://github.com/taller-de-programacion-2/2017-1c-music-io-app-server-grupo-1.git






