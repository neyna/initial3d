#ifndef FIRSTTRIANGLE_H_
#define FIRSTTRIANGLE_H_

#include <initial3d.hpp>

using namespace initial3d::objects;

namespace initial3d {
namespace projects {
namespace simpletriangle {


static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
	};

class SimpleTriangle : public ThreeDimensionsObject {
public:
	SimpleTriangle();
	virtual ~SimpleTriangle();
	virtual void initAfterOpenGLLoaded();
	void draw(std::shared_ptr<glm::mat4> modelViewProjectionMatrix);
protected:
	GLuint vertexbuffer;
	GLuint programId;
};

}
}
} /* namespace initial3d */
#endif /* FIRSTTRIANGLE_H_ */
