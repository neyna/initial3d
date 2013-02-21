cmake_minimum_required (VERSION 2.6)

project (INITIAL3D)
set (TEST_VERSION_MAJOR 0)
set (TEST_VERSION_MINOR 1)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})

# To put all executables to the specified directory
# this line creates a bug with the eclipse project file generation plugin
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

# Set eclipse version for project file generation (have to find a working version for the variable...)
#SET(CMAKE_ECLIPSE_VERSION 8)

add_subdirectory(src)

