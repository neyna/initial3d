#version 130

in vec3 fragmentColor;
out vec3 color;

void main() {
	// overrides color from model
	//color = fragmentColor;
	color = vec3(1,1,0);
}
