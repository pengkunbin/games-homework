#!/bin/bash

# 创建并进入构建目录
mkdir -p build
cd build

# 运行CMake和Make
cmake ..
make

# 运行可执行文件
./Transformation