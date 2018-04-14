cmake_minimum_required(VERSION 3.8)
project(cards)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES shuffle.c)
add_executable(cards ${SOURCE_FILES})