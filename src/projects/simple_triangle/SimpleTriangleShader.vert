#version 130

// if below extension if supported, we can use the 
// layout(location = 0) in vec3 vertexPosition_modelspace;
// else use 
// glBindAttribLocation(vertexShaderId, 0, "vertexPosition_modelspace");
// before linking phase
//#extension ARB_explicit_attrib_location : require

in vec3 vertexPosition;
in vec3 vertexColor;
uniform mat4 MVP;

out vec3 fragmentColor;

void main(){
	vec4 v = vec4(vertexPosition, 1); // Transform an homogeneous 4D vector
    gl_Position = MVP * v;
    fragmentColor = vertexColor;

}
