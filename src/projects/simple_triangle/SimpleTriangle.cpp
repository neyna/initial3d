#include <initial3d.hpp>
#include "SimpleTriangle.hpp"

using std::string;

namespace initial3d {
namespace projects {
namespace simpletriangle {

SimpleTriangle::SimpleTriangle() :
		ThreeDimensionsObject(stringPtr(new string("SimpleTriangleShader.vert")), stringPtr(new string("SimpleTriangleShader.frag")),
				sizeof(GLfloat), sizeof(g_vertex_buffer_data) / sizeof(GLfloat), 3, (void*) g_vertex_buffer_data) {
}

SimpleTriangle::~SimpleTriangle() {
}

}
}
} /* namespace initial3d */
