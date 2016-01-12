cmake_minimum_required (VERSION 3.4.0)
project (DataStructures)

set (CMAKE_CXX_FLAGS "-Werror -Wall -g -O0 -std=c++11")

add_subdirectory (utils)
add_subdirectory (algorithms)
add_subdirectory (exercises)
add_subdirectory (sorting)

