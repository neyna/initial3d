cmake_minimum_required (VERSION 2.6)

find_package(OpenGL REQUIRED)
find_package(SDL REQUIRED)

if(NOT SDL_FOUND)
  message(FATAL_ERROR "SDL required !")
  return()
endif()

if(NOT OPENGL_FOUND)
  message(FATAL_ERROR "OpenGL required !")
  return()
endif()

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${SDL_INCLUDE_DIR})

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/version.h"
  )

# add the binary tree to the search path for include files
# This enable us to find the test.h generated ealier
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

link_libraries(
    ${SDL_LIBRARY}
    ${OPENGL_LIBRARY}
)

add_executable(test base.c version.c)
