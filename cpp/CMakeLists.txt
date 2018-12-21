cmake_minimum_required (VERSION 3.4.0)
project (DataStructures)

set (CMAKE_CXX_COMPILER "llvm-g++")
set (CMAKE_CXX_FLAGS "-Werror -Wall -g -O0 -std=c++14")

add_subdirectory (utils)
add_subdirectory (algorithms)
add_subdirectory (exercises)
add_subdirectory (exercises/trees)
add_subdirectory (sorting)

