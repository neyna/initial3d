#ifndef THREEDIMENSIONSOBJECT_H_
#define THREEDIMENSIONSOBJECT_H_

namespace initial3d {
namespace objects {

class ThreeDimensionsObject {
public:
	/**
	 * Object constructor, do not put any openGL code here because the context may not have been initialized !
	 * Put such code in afterOpenGLInit method.
	 * TODO : add default shaders to that constructor
	 */
	ThreeDimensionsObject();
	ThreeDimensionsObject(stringPtr vertexShaderFilePath, stringPtr fragmentShaderFilePath,
			size_t dataSize, ulong vextexNumber, uint numberOfComponentPerVertex, void* data);
	virtual ~ThreeDimensionsObject();
	/**
	 * Here comes openGL code for the object initialization
	 */
	virtual void initAfterOpenGLLoaded();
	virtual void draw(std::shared_ptr<glm::mat4> &modelViewProjectionMatrix);
protected:
	stringPtr vertexShaderFilePath;
	stringPtr fragmentShaderFilePath;

	GLuint vertexbuffer;
	GLuint programId;

	// vertices
	size_t dataSize;
	ulong vertexNumber;
	uint numberOfComponentPerVertex;
	void* data;
};

typedef std::shared_ptr<ThreeDimensionsObject> ThreeDimensionObjectPtr;

}
} /* namespace initial3d */
#endif /* THREEDIMENSIONSOBJECT_H_ */
