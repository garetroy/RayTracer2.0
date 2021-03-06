CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12.1)

# Set project name
SET(PROJ_NAME "raytracer" CACHE STRING "name of project")
PROJECT(${PROJ_NAME})

# Set project options
SET(PROJ_EXT "cxx")
SET(BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../build/" CACHE STRING "location to build to")
SET(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../includes/" CACHE STRING "location of header files")
SET(MAX_ERR "5" CACHE STRING "maximum number of errors to display during compile")
SET(DEBUG_SUFFIX "_Debug" CACHE STRING "label to append to debug executable")
OPTION(DEBUG "enable debug flags at compile")

# Point to necessary project locations
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
INCLUDE_DIRECTORIES(${INCLUDE_DIR})
INCLUDE_DIRECTORIES(${INCLUDE_DIR}/objects)
INCLUDE_DIRECTORIES(${INCLUDE_DIR}/toolbox)
INCLUDE_DIRECTORIES(${INCLUDE_DIR}/tracers)
INCLUDE_DIRECTORIES(${INCLUDE_DIR}/samplers)
INCLUDE_DIRECTORIES(${INCLUDE_DIR}/cameras)
INCLUDE_DIRECTORIES(${INCLUDE_DIR}/brdfs)

# Setup project source compilation
ADD_EXECUTABLE(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.${PROJ_EXT}")
ADD_DEFINITIONS(-std=c++14 -fmax-errors=${MAX_ERR})
IF (DEBUG)
  MESSAGE("Generating debug version")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -DDEBUG=true")
  SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}${DEBUG_SUFFIX})
ELSE ()
  MESSAGE("Generating release version")
ENDIF ()

# Enable this if VTK is needed
SET(VTK_DIR "/Users/garett/Projects/RayTracer2.0/VTK-6.3.0")
FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

IF (VTK_LIBRARIES)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${VTK_LIBRARIES})
ELSE ()
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} vtkHybrid)
ENDIF ()
