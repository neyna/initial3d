#version 130
// if below extension if supported, we can use the 
// layout(location = 0) in vec3 vertexPosition_modelspace;
// else use 
// glBindAttribLocation(vertexShaderId, 0, "vertexPosition_modelspace");
// before linking phase
//#extension ARB_explicit_attrib_location : require

// Input vertex data, different for all executions of this shader.
in vec3 vertexPosition_modelspace;

void main(){

    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.w = 1.0;

}

