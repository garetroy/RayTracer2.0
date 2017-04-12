cmake_minimum_required(VERSION 2.8.12.1)

PROJECT(main)
SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
SET (CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")


file(GLOB SRCFILES
    "./include/*.h"
)


add_executable(main MACOSX_BUNDLE ${SRCFILES} main)

