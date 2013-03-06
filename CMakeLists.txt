cmake_minimum_required (VERSION 2.6)

project (INITIAL3D)
set (INITIAL3D_VERSION_MAJOR 0)
set (INITIAL3D_VERSION_MINOR 1)
set (INITIAL3D_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set (INITIAL3D_EXTERNAL_PATH ${INITIAL3D_ROOT_PATH}/externals) 

if (NOT CMAKE_BUILD_TYPE)
	message(STATUS "Build type defaulting to \"Debug\"")
	# "Release" "Debug"
	set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})
                      

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

# custom make target to download externals, add DL_DEP_TARGET to target ALL (make all)
add_custom_target(DL_DEP_TARGET ALL DEPENDS externals/glm-xxxx)

# To put all executables to the specified directory
# this line creates a bug with the eclipse project file generation plugin
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_subdirectory(src)

