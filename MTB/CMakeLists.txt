cmake_minimum_required(VERSION 3.19)
project(MTB)

set(CMAKE_CXX_STANDARD 14)

add_executable(MTB main.cpp mtb.cpp mtb.h ENUM_PARAMS.h)