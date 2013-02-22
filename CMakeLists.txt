cmake_minimum_required (VERSION 2.6)

project (INITIAL3D)
set (INITIAL3D_VERSION_MAJOR 0)
set (INITIAL3D_VERSION_MINOR 1)
set (INITIAL3D_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set (INITIAL3D_EXTERNAL_PATH ${INITIAL3D_ROOT_PATH}/externals) 

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})

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
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_subdirectory(src)

