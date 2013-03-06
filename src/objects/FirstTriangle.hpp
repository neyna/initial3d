#ifndef FIRSTTRIANGLE_H_
#define FIRSTTRIANGLE_H_

#include "../standard_includes.hpp"
#include "ThreeDimensionObject.hpp"

namespace initial3d {

static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
	};

class FirstTriangle : ThreeDimensionObject {
public:
	FirstTriangle();
	virtual ~FirstTriangle();
	void draw();
protected:
	GLuint vertexArrayID;
	GLuint vertexbuffer;
};

} /* namespace initial3d */
#endif /* FIRSTTRIANGLE_H_ */
