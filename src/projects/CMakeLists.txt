cmake_minimum_required (VERSION 2.6)

function(BuildInitial3dProject EXECUTABLE_NAME )

    # add initial3d includes
    set(ALL_INCLUDES ${INITIAL3D_INCLUDE_DIR} ${ALL_INCLUDES})

    include_directories(${ALL_INCLUDES})

    FILE(GLOB_RECURSE MY_PROJECT_HEADERS *.hpp)
    FILE(GLOB_RECURSE MY_PROJECT_SOURCES *.cpp)
    FILE(GLOB_RECURSE MY_PROJECT_DATA_FILES *.properties *.vert *.frag)

    FOREACH(PROJECT_DATA_FILE ${MY_PROJECT_DATA_FILES})
        # extract file name from absolute path
        get_filename_component(DATA_FILE_NAME ${PROJECT_DATA_FILE} NAME)
	    configure_file(${PROJECT_DATA_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${DATA_FILE_NAME} COPYONLY)
    ENDFOREACH()

    add_executable(${EXECUTABLE_NAME} ${MY_PROJECT_HEADERS} ${MY_PROJECT_SOURCES})

    set(ALL_LIBS initial3d ${ALL_LIBS})

    target_link_libraries(${EXECUTABLE_NAME} ${ALL_LIBS})

endfunction(BuildInitial3dProject)

# initial3d projects
add_subdirectory(simple_camera)
add_subdirectory(simple_triangle)
add_subdirectory(test_sphere)
