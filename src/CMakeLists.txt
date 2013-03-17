cmake_minimum_required (VERSION 2.6)

set(GLM_PACKAGE_DIR ${INITIAL3D_EXTERNAL_PATH}/glm-0.9.2.4)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)
find_package(GLM REQUIRED)
# For boost, format is already included (in base package)
find_package(Boost REQUIRED COMPONENTS filesystem)

# log libs
find_package(LOG4CXX REQUIRED)
find_package(APR REQUIRED)

if(NOT OPENGL_FOUND)
  message(FATAL_ERROR "OpenGL required !")
endif()

if(NOT GLEW_FOUND)
  message(FATAL_ERROR "GLEW required !")
endif()

if(NOT GLFW_FOUND)
  message(FATAL_ERROR "GlFW required !")
endif()

if(NOT GLM_FOUND)
  message(FATAL_ERROR "GLM required !")
endif()

if(NOT LOG4CXX_FOUND)
  message(FATAL_ERROR "LOG4CXX required !")
endif()

if(NOT APR_FOUND)
  message(FATAL_ERROR "APR required !")
endif()

if(NOT Boost_FOUND)
  message(FATAL_ERROR "Boost required !")
endif()

set(ALL_LIBS
	${OPENGL_LIBRARY}
	${GLEW_LIBRARY}
	${GLFW_LIBRARY}
	${LOG4CXX_LIBRARY}
	${APR_LIBRARY}
	${APRUTIL_LIBRARY}
	${Boost_LIBRARY}
)

set(ALL_INCLUDES
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
)


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

set(INITIAL3D_HEADER
		all_includes.hpp
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

        log4cxx.properties
	)


# Set and create dist directory
set(DIST_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/)
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${DIST_DIRECTORY})

# add files to clean
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_BINARY_DIR}/dist)

# SIMPLE TRIANGLE
set(SIMPLE_TRIANGLE_ADDITIONNAL_FILES
	log4cxx.properties
	projects/simple_triangle/SimpleTriangleShader.vert
	projects/simple_triangle/SimpleTriangleShader.frag
	)
set(SIMPLE_TRIANGLE_SOURCES
		projects/simple_triangle/SimpleTriangle.hpp
       	projects/simple_triangle/SimpleTriangleScene.hpp

       	projects/simple_triangle/SimpleTriangle.cpp
        projects/simple_triangle/main.cpp
        projects/simple_triangle/SimpleTriangleScene.cpp

        ${SIMPLE_TRIANGLE_ADDITIONNAL_FILES}
	)

set(SIMPLE_TRIANGLE_DIST_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/01_simple_triangle/)
add_executable(launcher ${INITIAL3D_HEADER} ${INITIAL3D_SOURCE} ${SIMPLE_TRIANGLE_SOURCES})

target_link_libraries(launcher ${ALL_LIBS})

add_custom_command(
   TARGET launcher PRE_BUILD
   COMMAND ${CMAKE_COMMAND} -E make_directory ${SIMPLE_TRIANGLE_DIST_DIRECTORY}
)

add_custom_command(
   TARGET launcher POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/launcher${CMAKE_EXECUTABLE_SUFFIX}" "${SIMPLE_TRIANGLE_DIST_DIRECTORY}"
)

FOREACH(SHADER ${SIMPLE_TRIANGLE_ADDITIONNAL_FILES})
	add_custom_command(
   		TARGET launcher POST_BUILD
   		COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${SHADER}" "${SIMPLE_TRIANGLE_DIST_DIRECTORY}"
	)
ENDFOREACH()
