cmake_minimum_required(VERSION 2.8.12.1)

PROJECT(main)
SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS}"} 
SET (CMAKE_CXX_FLAGS "-std=c++17 ${CMAKE_CXX_FLAGS}")


file(GLOB SRCFILES
    "./include/*"
)


add_executable(main MACOSX_BUNDLE ${SRCFILES} main)

