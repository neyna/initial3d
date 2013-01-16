cmake_minimum_required (VERSION 2.6)

find_package(OpenGL)

message("current source dir : ${CMAKE_CURRENT_SOURCE_DIR}")

if(NOT DEFINED OPENGL_FOUND)
  message("Failed to find openGL. Exiting...")
  return()
endif()

include_directories(${OPENGL_INCLUDE_DIR})

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/test.h.in"
  "${PROJECT_BINARY_DIR}/src/test.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}/src")

add_executable(test test.c)
