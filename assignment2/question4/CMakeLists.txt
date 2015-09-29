cmake_minimum_required(VERSION 3.3)
project(crc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp crc.c crc.h)
add_executable(crc ${SOURCE_FILES})