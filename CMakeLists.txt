cmake_minimum_required(VERSION 2.8)
project(hw2)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
add_definitions(-std=c99)

set(SOURCE_FILES src/main.c src/shell.h src/shell.c )
add_executable(hw2 ${SOURCE_FILES})