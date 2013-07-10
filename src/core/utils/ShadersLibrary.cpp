#include "ShadersLibrary.hpp"

namespace initial3d {
namespace utils {

std::string ShadersLibrary::DEFAULT_VERTEX_SHADER =
			"#version 130\n"
			"\n"
			"in vec3 vertexPosition;\n"
			"in vec3 vertexColor;\n"
			"uniform mat4 MVP;\n"
			"uniform int colorMode = 0; // 0 no color - 1 simpleColor - 2 colorArray\n"
			"vec3 noColor = vec3(1, 1, 1); // no color = white\n"
			"uniform vec3 simpleColor = vec3(1, 1, 1);\n"
			"\n"
			"out vec3 fragmentColor;\n"
			"\n"
			"void main(){\n"
			"	vec4 v = vec4(vertexPosition, 1); // Transform an homogeneous 4D vector\n"
			"    gl_Position = MVP * v;\n"
			"    if(colorMode == 0) {\n"
			"    	fragmentColor = noColor;\n"
			"    } else if(colorMode == 1) {\n"
			"    	fragmentColor = simpleColor;\n"
			"    } else {\n"
			"    	fragmentColor = vertexColor;\n"
			"    }\n"
			"\n"
			"}\n";

std::string ShadersLibrary::DEFAULT_FRAGMENT_SHADER =
			"#version 130\n"
			"\n"
			"in vec3 fragmentColor;\n"
			"out vec3 color;\n"
			"\n"
			"void main() {\n"
			"	color = fragmentColor;\n"
			"}\n";

ShadersLibrary::ShadersLibrary() {
}

ShadersLibrary::~ShadersLibrary() {
}


} /* namespace utils */
} /* namespace initial3d */
