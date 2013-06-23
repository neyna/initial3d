#ifndef SIMPLETETRAHEDRON_H_
#define SIMPLETETRAHEDRON_H_

#include <initial3d.hpp>

using namespace initial3d::objects;

namespace initial3d {
namespace projects {
namespace simplecamera {


static const GLfloat g_vertex_buffer_data[] = {
		// 1st triangle
		0.0f,  1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		// 2nd
		0.0f,  1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, -1.0f, -1.0f,
		// 3rd
		0.0f,  1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		0.0f, -1.0f, -1.0f,
		// bottom
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, -1.0f, -1.0f,
	};

static const GLfloat g_color_buffer_data[] = {
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		0.3f, 0.3f, 0.3f,
		0.3f, 0.3f, 0.3f,
		0.3f, 0.3f, 0.3f,
};

class Tetrahedron : ThreeDimensionObject {
public:
	Tetrahedron();
	virtual ~Tetrahedron();
	void draw(glm::mat4 modelViewProjectionMatrix);
protected:
	GLuint vertexArrayId;
	GLuint colorArrayId;
	GLuint vertexbuffer;
	GLuint programId;
};

}
}
} /* namespace initial3d */
#endif /* SIMPLETETRAHEDRON_H_ */
