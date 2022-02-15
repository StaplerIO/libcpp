cmake_minimum_required(VERSION 3.1)
project(libcpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/container)

add_executable(
        pair_test
        test/pair.cpp
)

add_executable(
        array_test
        test/array.cpp
)


add_executable(
        stack_test
        test/stack.cpp
)

add_executable(
        queue_test
        test/queue.cpp
)

add_library(libcpp
        src/condition/action_result.hpp
        src/container/array.hpp
        src/container/node.hpp
        src/container/pair.hpp
        src/container/queue.hpp
        src/container/stack.hpp)
