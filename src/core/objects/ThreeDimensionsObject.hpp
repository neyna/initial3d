#ifndef THREEDIMENSIONSOBJECT_H_
#define THREEDIMENSIONSOBJECT_H_

namespace initial3d {
namespace objects {

class ThreeDimensionsObject {
public:
	/**
	 * Object constructor, do not put any openGL code here because the context may not have been initialized !
	 * Put such code in afterOpenGLInit method.
	 * TODO : create a builder for ThreeDimensionsObject
	 */
	ThreeDimensionsObject(size_t dataSize, ulong vertexNumber, uint numberOfComponentPerVertex, void* vertexPostionData);
	ThreeDimensionsObject(stringPtr vertexShaderFilePath, stringPtr fragmentShaderFilePath,
			size_t dataSize, ulong vertexNumber, uint numberOfComponentPerVertex, void* vertexPostionData);
	virtual ~ThreeDimensionsObject();

	void addVertexColorData(void* vertexColorData);
	void setColor(glm::vec3 &color);

	/**
	 * Here comes openGL code for the object initialization
	 */
	virtual void initAfterOpenGLLoaded();
	virtual void draw(std::shared_ptr<glm::mat4> &modelViewProjectionMatrix);
protected:
	stringPtr vertexShaderSource;
	stringPtr fragmentShaderSource;

	GLuint vertexbufferId;
	GLuint colorArrayId;
	GLuint programId;

	// vertices
	size_t dataSize;
	ulong vertexNumber;
	uint numberOfComponentPerVertex;
	void* vertexPostionData;

	// color
	enum ColorMode {NO_COLOR = 0, ONE_COLOR = 1, ARRAY_COLOR = 2};
	/**
	 * Color mode :
	 * - NO_COLOR will be no color (see default value in shader)
	 * - ONE_COLOR will take color from 'color' field for all vertices
	 * - ARRAY_COLOR will take color from vertexColorData
	 */
	ColorMode colorMode = NO_COLOR;
	void* vertexColorData;
	glm::vec3 color;

};

typedef std::shared_ptr<ThreeDimensionsObject> ThreeDimensionObjectPtr;

}
} /* namespace initial3d */
#endif /* THREEDIMENSIONSOBJECT_H_ */
