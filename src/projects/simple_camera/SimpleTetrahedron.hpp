#ifndef SIMPLETETRAHEDRON_H_
#define SIMPLETETRAHEDRON_H_

#include <initial3d.hpp>

using namespace initial3d::objects;

namespace initial3d {
namespace projects {
namespace simplecamera {


static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
	};

class Tetrahedron : ThreeDimensionObject {
public:
	Tetrahedron();
	virtual ~Tetrahedron();
	void draw(glm::mat4 modelViewProjectionMatrix);
protected:
	GLuint vertexArrayID;
	GLuint vertexbuffer;
	GLuint programId;
};

}
}
} /* namespace initial3d */
#endif /* SIMPLETETRAHEDRON_H_ */
