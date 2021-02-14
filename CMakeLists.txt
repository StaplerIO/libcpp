cmake_minimum_required(VERSION 3.1)
project(libcpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/container)

add_executable(
        pair_test
        test/pair.cpp
        src/container/pair.hpp
)

add_executable(
        array_test
        test/array.cpp
        src/container/node.hpp
        src/container/array.hpp
)
