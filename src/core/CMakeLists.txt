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

# Generate empty ShadersLibrary.cpp (we need to do it during CMake generation or it will fail to find the source for initial config. The real file will be generated on each build after)
execute_process(COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/ShadersLibrary.cpp)
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

# workaround to be sure that ShadersLibrary.cpp is generated each time there are modification in the shader sources
SET(SHADERSLIBRARY_CPP_IN ${CMAKE_CURRENT_SOURCE_DIR}/utils/ShadersLibrary.cpp.in)
ADD_CUSTOM_TARGET(refresh_ShadersLibrary
                  DEPENDS ${DEFAULT_FRAGMENT_SHADER_FILE}
                          ${DEFAULT_VERTEX_SHADER_FILE}
                  # Note that -P must be the last flag, or the -D flags won't work.
                  COMMAND ${CMAKE_COMMAND} -DSHADERSLIBRARY_CPP_IN=${SHADERSLIBRARY_CPP_IN} -DMY_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR} -DMY_CURRENT_BINARY_DIR=${CMAKE_CURRENT_BINARY_DIR} -P ${CMAKE_CURRENT_SOURCE_DIR}/shaderLibray.cmake
)

ADD_DEPENDENCIES( initial3d refresh_ShadersLibrary )

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