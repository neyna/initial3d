#include "../initial3d.hpp"

using glm::mat4;
using std::shared_ptr;
using std::vector;
using std::string;
using namespace initial3d::utils;

namespace initial3d {
namespace objects {

ThreeDimensionsObject::~ThreeDimensionsObject() {
	// release buffers
	glDeleteBuffers(1, &vertexbufferId);
	if( vertexColorData != NULL ) {
		glDeleteBuffers(1, &colorArrayId);
	}
}

void ThreeDimensionsObject::initAfterOpenGLLoaded() {
	// vertex buffer
	glGenBuffers(1, &vertexbufferId);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferId);
	glBufferData(GL_ARRAY_BUFFER, vertexNumber * dataSize, vertexPostionData, GL_STATIC_DRAW);

	// color buffer
	if( vertexColorData != NULL ) {
		glGenBuffers(1, &colorArrayId);
		glBindBuffer(GL_ARRAY_BUFFER, colorArrayId);
		glBufferData(GL_ARRAY_BUFFER, vertexNumber * dataSize, vertexColorData, GL_STATIC_DRAW);
	}

	shared_ptr<vector<string>> parameterNamesPtr(new vector<string>( {string("vertexPosition"), string("vertexColor") }));
	programId = ShaderLoader::loadShaders(vertexShaderFilePath->c_str(), fragmentShaderFilePath->c_str(), parameterNamesPtr);
}

ThreeDimensionsObject::ThreeDimensionsObject(stringPtr vertexShaderFilePath, stringPtr fragmentShaderFilePath,
		size_t dataSize, ulong vertexNumber, uint numberOfComponentPerVertex, void* vertexPostionData) :
		vertexShaderFilePath(vertexShaderFilePath), fragmentShaderFilePath(fragmentShaderFilePath),
		vertexbufferId(0), colorArrayId(0), programId(0), dataSize(dataSize), vertexNumber(vertexNumber),
		numberOfComponentPerVertex(numberOfComponentPerVertex), vertexPostionData(vertexPostionData), vertexColorData(NULL) {
	// assert vertexNumber is a multiple of numberOfComponentPerVertex
	assert( (vertexNumber % numberOfComponentPerVertex) == 0);
}

ThreeDimensionsObject::ThreeDimensionsObject() :
		vertexShaderFilePath(nullptr), fragmentShaderFilePath(nullptr),
		vertexbufferId(0), colorArrayId(0), programId(0), dataSize(0), vertexNumber(0), numberOfComponentPerVertex(3),
		vertexPostionData(0), vertexColorData(0) {
}

void ThreeDimensionsObject::addVertexColorData(void* vertexColorData) {
	this->vertexColorData = vertexColorData;
}

void ThreeDimensionsObject::draw(shared_ptr<mat4> &modelViewProjectionMatrix) {
	// use the shaders
	glUseProgram(programId);

	GLuint matrixID = glGetUniformLocation(programId, "MVP");

	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &(*modelViewProjectionMatrix.get())[0][0]);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferId);
	glVertexAttribPointer(0, 			// attribute 0. No particular reason for 0, but must match the layout in the shader.
			numberOfComponentPerVertex, // Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4. Additionally, the symbolic constant GL_BGRA is accepted by glVertexAttribPointer. The initial value is 4
			GL_FLOAT,           		// type
			GL_FALSE,           		// normalized?
			0,                  		// stride
			(void*) 0           		// array buffer offset
			);

	// 2nd attribute buffer : colors
	if( vertexColorData != NULL ) {
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorArrayId);
		glVertexAttribPointer(1, numberOfComponentPerVertex, GL_FLOAT, GL_FALSE, 0, (void*)0);
	}

	glDrawArrays(GL_TRIANGLES, 0, vertexNumber / numberOfComponentPerVertex);

	glDisableVertexAttribArray(0);
	if( vertexColorData != NULL ) {
		glDisableVertexAttribArray(1);
	}

	printOpenGLErrors();
}

}
}


