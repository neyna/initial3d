cmake_minimum_required (VERSION 2.6)

project (INITIAL3D)
set (INITIAL3D_VERSION_MAJOR 0)
set (INITIAL3D_VERSION_MINOR 1)
set (INITIAL3D_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set (INITIAL3D_EXTERNAL_PATH ${INITIAL3D_ROOT_PATH}/externals)

# set build type
if (NOT CMAKE_BUILD_TYPE)
	message(STATUS "Build type defaulting to \"Debug\"")
	# "Release" "Debug"
	set(CMAKE_BUILD_TYPE "Debug")
endif()

# tell cmake where to find modules
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})


# set flags for compiler
if(CMAKE_COMPILER_IS_GNUCXX)
	message("Settings options for GNUCXX")
	set(COMMON_GNUCXX_FLAGS "-std=c++0x -Wall")
	set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${COMMON_GNUCXX_FLAGS} -O0 -Wextra -DDEBUG -D_DEBUG")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${COMMON_GNUCXX_FLAGS} -O0 -Wextra -DDEBUG -D_DEBUG")
	set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${COMMON_GNUCXX_FLAGS} -O3")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${COMMON_GNUCXX_FLAGS} -O3")
endif(CMAKE_COMPILER_IS_GNUCXX)

# Downloading dependencies
IF (WIN32)
    # Execute Win32 Specific commands - none yet.
ELSE (WIN32)
    # Execute commands for other platforms
    ADD_CUSTOM_COMMAND(
        OUTPUT externals/glm-xxxx
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/externals/install_dependencies.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/externals
        COMMENT "Download dependencies..."
    )
ENDIF (WIN32)

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

# custom make target to download externals, add DL_DEP_TARGET to target ALL (make all)
add_custom_target(DL_DEP_TARGET ALL DEPENDS externals/glm-xxxx)

# To put all executables to the specified directory
# this line creates a bug with the eclipse project file generation plugin
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

set(DIST_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/)

add_subdirectory(src)

