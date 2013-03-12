cmake_minimum_required (VERSION 2.6)

set(GLM_PACKAGE_DIR ${INITIAL3D_EXTERNAL_PATH}/glm-0.9.2.4)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)
find_package(GLM REQUIRED)

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

set(ALL_LIBS
	${OPENGL_LIBRARY}
	${GLEW_LIBRARY}
	${GLFW_LIBRARY}
)

set(ALL_INCLUDES
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIR})

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
       
        objects/ThreeDimensionObject.hpp
        scene/Scene.hpp
        system/Launcher.hpp
        system/GLFWLauncher.hpp
        utils/FPSTimer.hpp    
	)

set(INITIAL3D_SOURCE
        scene/Scene.cpp
        system/Launcher.cpp
        system/GLFWLauncher.cpp
        utils/FPSTimer.cpp
        utils/version.cpp        
	)


# Set and create dist directory
set(DIST_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/)
file(MAKE_DIRECTORY ${DIST_DIRECTORY})  

# add files to clean
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_CURRENT_BINARY_DIR}/dist) 
   
# SIMPLE TRIANGLE
set(SIMPLE_TRIANGLE_SHADERS
	projects/simple_triangle/shader.a
	)
set(SIMPLE_TRIANGLE_SOURCES
		projects/simple_triangle/FirstTriangle.hpp
       	projects/simple_triangle/SimpleTriangleScene.hpp
       	
       	projects/simple_triangle/FirstTriangle.cpp
        projects/simple_triangle/main.cpp
        projects/simple_triangle/SimpleTriangleScene.cpp
        
        ${SIMPLE_TRIANGLE_SHADERS}
	)

add_executable(launcher ${INITIAL3D_HEADER} ${INITIAL3D_SOURCE} ${SIMPLE_TRIANGLE_SOURCES})

target_link_libraries(launcher ${ALL_LIBS})

set(SIMPLE_TRIANGLE_DIST_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/01_simple_triangle)
file(MAKE_DIRECTORY ${SIMPLE_TRIANGLE_DIST_DIRECTORY})

add_custom_command(
   TARGET launcher POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/launcher${CMAKE_EXECUTABLE_SUFFIX}" "${SIMPLE_TRIANGLE_DIST_DIRECTORY}"
)

FOREACH(SHADER ${SIMPLE_TRIANGLE_SHADERS})
	add_custom_command(
   		TARGET launcher POST_BUILD
   		COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${SHADER}" "${SIMPLE_TRIANGLE_DIST_DIRECTORY}"
	)
ENDFOREACH()
