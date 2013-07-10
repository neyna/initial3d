Readme.

License : GPL

To build projects :
  cd [....]/initial3d
  mkdir build
  cd build
  cmake ..
  make


Default Vertex Shader :
#version 130

in vec3 vertexPosition;
in vec3 vertexColor;
uniform mat4 MVP;
uniform int colorMode = 0; // 0 no color - 1 simpleColor - 2 colorArray 
vec3 noColor = vec3(1, 1, 1); // no color = white
uniform vec3 simpleColor = vec3(1, 1, 1); 

out vec3 fragmentColor;

void main(){
	vec4 v = vec4(vertexPosition, 1); // Transform an homogeneous 4D vector
    gl_Position = MVP * v;
    if(colorMode == 0) {
    	fragmentColor = noColor;
    } else if(colorMode == 1) {
    	fragmentColor = simpleColor;
    } else {
    	fragmentColor = vertexColor;
    }

}


Default Fragment shader :

#version 130

in vec3 fragmentColor;
out vec3 color;

void main() {
	color = fragmentColor;
}

