cmake_minimum_required (VERSION 2.6)

set(GLM_PACKAGE_DIR ${INITIAL3D_EXTERNAL_PATH}/glm-0.9.2.4)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)
find_package(GLM REQUIRED)

if(NOT OPENGL_FOUND)
  message(FATAL_ERROR "OpenGL required !")
  return()
endif()

if(NOT GLEW_FOUND)
  message(FATAL_ERROR "GLEW required !")
  return()
endif()

if(NOT GLFW_FOUND)
  message(FATAL_ERROR "GlFW required !")
  return()
endif()

if(NOT GLM_FOUND)
  message(FATAL_ERROR "GLM required !")
  return()
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
  ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.h
  )

# add the binary tree to the search path for include files
# This enable us to find the test.h generated ealier
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(INITIAL3D_HEADER 
        ${CMAKE_CURRENT_BINARY_DIR}/version.h    
        Launcher.h
        main.h 
        objects/FirstTriangle.h 
        objects/ThreeDimensionObject.h 
        standard_includes.h              
   )

set(INITIAL3D_SOURCE 
        Launcher.cpp
        main.cpp
        version.cpp
        objects/FirstTriangle.cpp
   )

add_executable(launcher ${INITIAL3D_HEADER} ${INITIAL3D_SOURCE})

target_link_libraries(launcher ${ALL_LIBS})
