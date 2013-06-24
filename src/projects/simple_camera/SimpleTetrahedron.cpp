#include <initial3d.hpp>
#include "SimpleTetrahedron.hpp"

using glm::vec3;
using glm::mat4;
using namespace std;
using namespace initial3d::utils;

namespace initial3d {
namespace projects {
namespace simplecamera {

Tetrahedron::Tetrahedron() {
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	// vertex array
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);

	// vertex buffer
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	// color
	glGenBuffers(1, &colorArrayId);
	glBindBuffer(GL_ARRAY_BUFFER, colorArrayId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

	shared_ptr<vector<string>> sharedPtrVectorString(new vector<string>({string("vertexPosition"), string("vertexColor")}));
	programId = ShaderLoader::loadShaders("SimpleTetrahedronShader.vert", "SimpleTetrahedronShader.frag", sharedPtrVectorString);

	printOpenGLErrors();

}

Tetrahedron::~Tetrahedron() {
	// release buffers
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &colorArrayId);
	glDeleteVertexArrays(1, &vertexArrayId);
}


void Tetrahedron::draw(std::shared_ptr<glm::mat4> modelViewProjectionMatrix) {

	// We don't have model computed by the scene at the moment
	// it will be computed by the engine when objets will have coordinates
	mat4 model = mat4(1.0f);  // Changes for each model !
	mat4 MVP = (*modelViewProjectionMatrix.get()) * model;


	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT GL_STENCIL_BUFFER_BIT

	// use the shaders
	glUseProgram(programId);

	GLuint matrixID = glGetUniformLocation(programId, "MVP");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
			0, // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*) 0            // array buffer offset
			);

	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorArrayId);
	glVertexAttribPointer(
	    1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
	    3,                                // size
	    GL_FLOAT,                         // type
	    GL_FALSE,                         // normalized?
	    0,                                // stride
	    (void*)0                          // array buffer offset
	);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, triangleNumber * 3); // triangleNumber * 3 vertices

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	printOpenGLErrors();

}

}
}
} /* namespace initial3d */
