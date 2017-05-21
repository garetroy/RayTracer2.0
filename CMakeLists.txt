cmake_minimum_required(VERSION 2.8)

PROJECT(main C CXX)
SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
SET (CMAKE_CXX_FLAGS "-std=c++11 -g ${CMAKE_CXX_FLAGS}")
set(VTK_DIR "./VTK-6.3.0/")

file(GLOB SRCFILES
    "./include/*.h"
    "main.cxx"
)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(main ${SRCFILES} main)
target_link_libraries(main ${VTK_LIBRARIES})


SET_TARGET_PROPERTIES (
    main
    PROPERTIES LINKER_LANGUAGE CXX
)
