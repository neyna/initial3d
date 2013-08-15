cmake_minimum_required (VERSION 2.6)

#configure header for default shaders
SET(DEFAULT_FRAGMENT_SHADER_FILE "${MY_CURRENT_SOURCE_DIR}/data/defaultFragmentShader.frag")
SET(DEFAULT_VERTEX_SHADER_FILE "${MY_CURRENT_SOURCE_DIR}/data/defaultVertexShader.vert")

FILE(STRINGS ${DEFAULT_FRAGMENT_SHADER_FILE} DEFAULT_FRAGMENT_SHADER_SOURCE NEWLINE_CONSUME)
FILE(STRINGS ${DEFAULT_VERTEX_SHADER_FILE} DEFAULT_VERTEX_SHADER_SOURCE NEWLINE_CONSUME)

#replace newlines with a string substitute
STRING(REGEX REPLACE "\n" "\\\\n" DEFAULT_FRAGMENT_SHADER_SOURCE ${DEFAULT_FRAGMENT_SHADER_SOURCE})
STRING(REGEX REPLACE "\n" "\\\\n" DEFAULT_VERTEX_SHADER_SOURCE ${DEFAULT_VERTEX_SHADER_SOURCE})

configure_file (
  ${SHADERSLIBRARY_CPP_IN}
  ${MY_CURRENT_BINARY_DIR}/ShadersLibrary.cpp
  )