#ifndef THREEDIMENSIONSOBJECT_H_
#define THREEDIMENSIONSOBJECT_H_

namespace initial3d {
namespace objects {

class ThreeDimensionsObject {
public:
	/**
	 * Object constructor, do not put any openGL code here because the context may not have been initialized !
	 * Put such code in afterOpenGLInit method.
	 */
	virtual ~ThreeDimensionsObject() {};
	/**
	 * Here comes openGL code for the object initialization
	 */
	virtual void initAfterOpenGLLoaded() = 0;
	virtual void draw(std::shared_ptr<glm::mat4> modelViewProjectionMatrix) = 0;
};

typedef std::shared_ptr<ThreeDimensionsObject> ThreeDimensionObjectPtr;

}
} /* namespace initial3d */
#endif /* THREEDIMENSIONSOBJECT_H_ */
