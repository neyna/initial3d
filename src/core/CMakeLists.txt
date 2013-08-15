cmake_minimum_required (VERSION 2.6)

include_directories(${ALL_INCLUDES})

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  ${CMAKE_CURRENT_SOURCE_DIR}/utils/version.hpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.hpp
  )

# add the binary tree to the search path for include files
# This enable us to find the test.h generated ealier
include_directories(${CMAKE_CURRENT_BINARY_DIR})


#configure header for default shaders
FILE(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/data/defaultFragmentShader.frag" DEFAULT_FRAGMENT_SHADER_SOURCE NEWLINE_CONSUME)
FILE(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/data/defaultVertexShader.vert" DEFAULT_VERTEX_SHADER_SOURCE NEWLINE_CONSUME)
#replace newlines with a string substitute
STRING(REGEX REPLACE "\n" "\\\\n" DEFAULT_FRAGMENT_SHADER_SOURCE ${DEFAULT_FRAGMENT_SHADER_SOURCE})
STRING(REGEX REPLACE "\n" "\\\\n" DEFAULT_VERTEX_SHADER_SOURCE ${DEFAULT_VERTEX_SHADER_SOURCE})

configure_file (
  ${CMAKE_CURRENT_SOURCE_DIR}/utils/ShadersLibrary.cpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/ShadersLibrary.cpp
  )
# need this to compile ShadersLibrary.cpp (add the directory where is its header to -I)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)

FILE(GLOB_RECURSE INITIAL3D_HEADER *.hpp)
SET(INITIAL3D_HEADER ${INITIAL3D_HEADER} ${CMAKE_CURRENT_BINARY_DIR}/version.hpp)

FILE(GLOB_RECURSE INITIAL3D_SOURCE *.cpp)
SET(INITIAL3D_SOURCE ${INITIAL3D_SOURCE} ${CMAKE_CURRENT_BINARY_DIR}/ShadersLibrary.cpp)

# export variable to parent, but care it is undefined for us
# we add ${CMAKE_CURRENT_BINARY_DIR for version.hpp (TODO : need to look for a nicer solution)
SET(INITIAL3D_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)

ADD_LIBRARY(initial3d STATIC ${INITIAL3D_HEADER} ${INITIAL3D_SOURCE})

# add dist to clean
#set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${DIST_DIRECTORY})

#SET(INITIAL3D_STATIC_LIB ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/${CMAKE_STATIC_LIBRARY_PREFIX}initial3d${CMAKE_STATIC_LIBRARY_SUFFIX})
#SET(INITIAL3D_SHARED_LIB ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/${CMAKE_SHARED_LIBRARY_PREFIX}initial3d${CMAKE_SHARED_LIBRARY_SUFFIX})

# create dist
#add_custom_command(
#   TARGET initial3d PRE_BUILD
#   COMMAND ${CMAKE_COMMAND} -E make_directory ${DIST_DIRECTORY}
#)

#add_custom_command(
#   TARGET initial3d POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${INITIAL3D_STATIC_LIB}" "${DIST_DIRECTORY}"
#)