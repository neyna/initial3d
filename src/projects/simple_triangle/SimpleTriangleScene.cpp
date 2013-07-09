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
			stringPtr(new string("SimpleTriangleShader.vert")),	stringPtr(new string("SimpleTriangleShader.frag")),
			sizeof(GLfloat),														// size_t of vertices datatype
			sizeof(g_vertex_buffer_data) / sizeof(GLfloat),							// number of vertices
			3, 																		// number of data per vertex
			(void*) g_vertex_buffer_data 											// vertices data
			)
	);

	addObject(simpleTriangle);
}

SimpleTriangleScene::~SimpleTriangleScene() {
}

}
}
} /* namespace initial3d */
