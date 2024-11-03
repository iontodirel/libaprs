#!/bin/sh
apt-get install -y software-properties-common
add-apt-repository -y ppa:ubuntu-toolchain-r/test
apt-get install -y gcc g++ gcc-13 g++-13 clang make cmake ninja-build