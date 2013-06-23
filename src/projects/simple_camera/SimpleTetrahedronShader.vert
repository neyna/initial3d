#version 130

in vec3 vertexPosition;
in vec3 vertexColor;
uniform mat4 MVP;

out vec3 fragmentColor;

void main(){
	vec4 v = vec4(vertexPosition,1); // Transform an homogeneous 4D vector
    gl_Position = MVP * v;
    fragmentColor = vertexColor;

}

