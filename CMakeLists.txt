cmake_minimum_required(VERSION 2.8.12.1)

PROJECT(main)
find_package(OpenMP)
IF(OPENMP_FOUND)
    SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    SET (CMAKE_CXX_FLAGS "-std=c++17 ${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()


file(GLOB SRCFILES
    "*.h"
    "*.cxx"
)


add_executable(main MACOSX_BUNDLE ${SRCFILES} main)

