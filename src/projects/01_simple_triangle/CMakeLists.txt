cmake_minimum_required (VERSION 2.6)

set(EXECUTABLE_NAME simple_triangle)

BuildInitial3dProject(${EXECUTABLE_NAME})

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
