#include <initial3d.hpp>
#include "SimpleTetrahedron.hpp"

using namespace initial3d::utils;

namespace initial3d {
namespace projects {
namespace simplecamera {

Tetrahedron::Tetrahedron() {
	// vertex array
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	// vertex buffer
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	programId = ShaderLoader::loadShaders("SimpleTetrahedronShader.vert", "SimpleTetrahedronShader.frag");
}

Tetrahedron::~Tetrahedron() {
	// release buffers
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
}


void Tetrahedron::draw(glm::mat4 modelViewProjectionMatrix) {

	// We don't have model computed by the scene at the moment
	mat4 model = mat4(1.0f);  // Changes for each model !
	mat4 MVP = modelViewProjectionMatrix * model;


	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT GL_STENCIL_BUFFER_BIT

	// use the shaders
	glUseProgram(programId);

	GLuint matrixID = glGetUniformLocation(programId, "MVP");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

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
