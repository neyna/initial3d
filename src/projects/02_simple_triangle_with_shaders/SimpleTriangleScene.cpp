#include "SimpleTriangleScene.hpp"

using initial3d::objects::ThreeDimensionsObject;
using std::string;

namespace initial3d {
namespace projects {
namespace simpletriangle {

static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
	};

SimpleTriangleScene::SimpleTriangleScene() {
	simpleTriangle = std::shared_ptr<ThreeDimensionsObject>(new ThreeDimensionsObject(
			sizeof(GLfloat),														// size_t of vertices datatype
			3, 																		// number of data per vertex
			stringPtr(new string("SimpleTriangleShader.vert")),	stringPtr(new string("SimpleTriangleShader.frag"))
			)
	);
	simpleTriangle->setVertexData((void*) g_vertex_buffer_data, sizeof(g_vertex_buffer_data) / sizeof(GLfloat));

	addObject(simpleTriangle);
}

SimpleTriangleScene::~SimpleTriangleScene() {
}

}
}
} /* namespace initial3d */
