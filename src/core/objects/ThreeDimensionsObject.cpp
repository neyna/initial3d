#include "../initial3d.hpp"

using glm::mat4;
using std::shared_ptr;
using namespace initial3d::utils;

namespace initial3d {
namespace objects {

ThreeDimensionsObject::~ThreeDimensionsObject() {
	// release buffers
	glDeleteBuffers(1, &vertexbuffer);
}

void ThreeDimensionsObject::initAfterOpenGLLoaded() {
	// vertex buffer
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexNumber * dataSize, data, GL_STATIC_DRAW);

	programId = ShaderLoader::loadShaders(vertexShaderFilePath->c_str(), fragmentShaderFilePath->c_str());
}

ThreeDimensionsObject::ThreeDimensionsObject(stringPtr vertexShaderFilePath, stringPtr fragmentShaderFilePath,
		size_t dataSize, ulong vertexNumber, uint numberOfComponentPerVertex, void* data) :
		vertexShaderFilePath(vertexShaderFilePath), fragmentShaderFilePath(fragmentShaderFilePath),
		vertexbuffer(0), programId(0), dataSize(dataSize), vertexNumber(vertexNumber),
		numberOfComponentPerVertex(numberOfComponentPerVertex), data(data) {
	// assert vertexNumber is a multiple of numberOfComponentPerVertex
	assert( (vertexNumber % numberOfComponentPerVertex) == 0);
}

ThreeDimensionsObject::ThreeDimensionsObject() :
		vertexShaderFilePath(nullptr), fragmentShaderFilePath(nullptr),
		vertexbuffer(0), programId(0), dataSize(0), vertexNumber(0), numberOfComponentPerVertex(3), data(0) {
}

void ThreeDimensionsObject::draw(shared_ptr<mat4> &modelViewProjectionMatrix) {
	// use the shaders
	glUseProgram(programId);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, // attribute 0. No particular reason for 0, but must match the layout in the shader.
			numberOfComponentPerVertex, // Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4. Additionally, the symbolic constant GL_BGRA is accepted by glVertexAttribPointer. The initial value is 4
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*) 0            // array buffer offset
			);

	glDrawArrays(GL_TRIANGLES, 0, vertexNumber / numberOfComponentPerVertex); // 3 indices starting at 0 -> 1 triangle

	glDisableVertexAttribArray(0);
}

}
}


