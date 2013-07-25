#ifndef THREEDIMENSIONSOBJECT_H_
#define THREEDIMENSIONSOBJECT_H_

#include "../initial3d_basics.hpp"

namespace initial3d {
namespace objects {

/**
 * Base object of this framework.
 *
 * Notes :
 * - Do not put any any openGL code in constructors because the context may not have been initialized ! (Put such code in afterOpenGLInit method.)
 */
class ThreeDimensionsObject {
public:
	/**
	 * Use default shaders
	 * @param dataSize Size of data passed to the openGL pipeline for vertices and color data (for example use sizeof(GLFloat))
	 * @param numberOfComponentPerVertex number of components per vertex passed to the openGL pipeline (often 3 : x, y, z)
	 */
	ThreeDimensionsObject(size_t dataSize, uint numberOfComponentPerVertex);
	ThreeDimensionsObject(size_t dataSize, uint numberOfComponentPerVertex, stringPtr vertexShaderFilePath, stringPtr fragmentShaderFilePath);

	virtual ~ThreeDimensionsObject();

	void setVertexData(void* vertexPostionData, ulong vertexNumber);
	/**
	 * To add vertex color data, you must use setVertexData first
	 */
	void setVertexColorData(void* vertexColorData);
	void setColor(glm::vec3 &color);
	void setPosition(glm::vec3 &position);

	/**
	 * Here comes openGL code for the object initialization
	 */
	virtual void initAfterOpenGLLoaded();
	virtual void draw(std::shared_ptr<glm::mat4> &modelViewProjectionMatrix);
protected:
	ThreeDimensionsObject(size_t dataSize, uint numberOfComponentPerVertex,
			std::string* vertexShaderSource, std::string* fragmentShaderSource);
	void createOpenGLBuffers();
	void destroyOpenGLBuffers();
	void renewOpenGLBuffers();

	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	float scalingFactor = 1.0f;

	stringPtr vertexShaderSource = nullptr;
	stringPtr fragmentShaderSource = nullptr;

	GLuint vertexbufferId = 0;
	GLuint colorArrayId = 0;
	GLuint programId = 0;

	// vertices
	size_t dataSize = 0;
	ulong vertexNumber = 0;
	uint numberOfComponentPerVertex = 3;
	void* vertexPostionData = NULL;

	// color
	enum ColorMode : GLint {NO_COLOR = 0, ONE_COLOR = 1, ARRAY_COLOR = 2};
	/**
	 * Color mode :
	 * - NO_COLOR will be no color (see default value in shader)
	 * - ONE_COLOR will take color from 'color' field for all vertices
	 * - ARRAY_COLOR will take color from vertexColorData
	 */
	ColorMode colorMode = NO_COLOR;
	void* vertexColorData = NULL;
	glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f);

};

typedef std::shared_ptr<ThreeDimensionsObject> ThreeDimensionObjectPtr;

}
} /* namespace initial3d */
#endif /* THREEDIMENSIONSOBJECT_H_ */
