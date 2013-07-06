#include <initial3d.hpp>
#include "SimpleTriangle.hpp"

using namespace initial3d::utils;

namespace initial3d {
namespace projects {
namespace simpletriangle {

SimpleTriangle::SimpleTriangle(): vertexbuffer(0), programId(0) {
}

void SimpleTriangle::initAfterOpenGLLoaded() {
	// vertex buffer
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	programId = ShaderLoader::loadShaders("SimpleTriangleShader.vert", "SimpleTriangleShader.frag");
}

SimpleTriangle::~SimpleTriangle() {
	// release buffers
	glDeleteBuffers(1, &vertexbuffer);
}


void SimpleTriangle::draw(std::shared_ptr<glm::mat4> modelViewProjectionMatrix) {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT GL_STENCIL_BUFFER_BIT

	// use the shaders
	glUseProgram(programId);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*) 0            // array buffer offset
			);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

	glDisableVertexAttribArray(0);

}

}
}
} /* namespace initial3d */
