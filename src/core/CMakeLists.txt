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


#TODO cmake file GLOB
set(INITIAL3D_HEADER
		initial3d.hpp
        ${CMAKE_CURRENT_BINARY_DIR}/version.hpp
        standard_includes.hpp

		exception/Initial3dException.hpp
        objects/ThreeDimensionObject.hpp
        scene/Scene.hpp
        system/Launcher.hpp
        system/GLFWLauncher.hpp
        utils/FPSTimer.hpp
        utils/ShaderLoader.hpp
	)

set(INITIAL3D_SOURCE
		exception/Initial3dException.cpp
        scene/Scene.cpp
        system/Launcher.cpp
        system/GLFWLauncher.cpp
        utils/FPSTimer.cpp
        utils/ShaderLoader.cpp
        utils/version.cpp
	)

# export variable to parent, but care it is undefined for us
# we add ${CMAKE_CURRENT_BINARY_DIR for version.hpp (TODO : need to look for a nicer solution)
SET(INITIAL3D_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)

ADD_LIBRARY(initial3d STATIC ${INITIAL3D_HEADER} ${INITIAL3D_SOURCE})

# add dist to clean
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${DIST_DIRECTORY})

SET(INITIAL3D_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)

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