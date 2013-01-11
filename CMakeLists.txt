cmake_minimum_required (VERSION 2.6)

project (Test)
set (Test_VERSION_MAJOR 0)
set (Test_VERSION_MINOR 1)

add_subdirectory(src)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/test.h.in"
  "${PROJECT_BINARY_DIR}/test.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

add_executable(test test.c)
