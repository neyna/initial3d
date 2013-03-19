cmake_minimum_required (VERSION 2.6)

# add initial3d includes
set(ALL_INCLUDES ${INITIAL3D_INCLUDE_DIR} ${ALL_INCLUDES})

include_directories(${ALL_INCLUDES})

#TODO cmake file GLOB
# SIMPLE TRIANGLE
set(PROJECT_DATA_FILES
	log4cxx.properties
	SimpleTriangleShader.vert
	SimpleTriangleShader.frag
	)
set(PROJECT_SOURCES
		SimpleTriangle.hpp
       	SimpleTriangleScene.hpp

       	SimpleTriangle.cpp
        main.cpp
        SimpleTriangleScene.cpp

        ${PROJECT_DATA_FILES}
	)



FOREACH(PROJECT_FILE ${PROJECT_DATA_FILES})
	configure_file(${PROJECT_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_FILE} COPYONLY)
	#set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${ADDITIONAL_MAKE_CLEAN_FILES} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_FILE})
ENDFOREACH()



#set(SIMPLE_TRIANGLE_DIST_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/01_simple_triangle/)
add_executable(launcher ${PROJECT_SOURCES})

set(ALL_LIBS initial3d ${ALL_LIBS})

target_link_libraries(launcher ${ALL_LIBS})

#add_custom_command(
#   TARGET launcher PRE_BUILD
#   COMMAND ${CMAKE_COMMAND} -E make_directory ${SIMPLE_TRIANGLE_DIST_DIRECTORY}
#)
#
#add_custom_command(
#   TARGET launcher POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/launcher${CMAKE_EXECUTABLE_SUFFIX}" "${SIMPLE_TRIANGLE_DIST_DIRECTORY}"
#)
#
#FOREACH(ADDITIONNAL_FILE ${SIMPLE_TRIANGLE_ADDITIONNAL_FILES})
#	add_custom_command(
#   		TARGET launcher POST_BUILD
#   		COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${ADDITIONNAL_FILE}" "${SIMPLE_TRIANGLE_DIST_DIRECTORY}"
#	)
#ENDFOREACH()
