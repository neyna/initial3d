#ifndef THREEDIMENSIONOBJECT_H_
#define THREEDIMENSIONOBJECT_H_

namespace initial3d {
namespace objects {

class ThreeDimensionObject {
public:
	/**
	 * Object constructor, do not put any openGL code here because the context may not have been initialized !
	 * Put such code in afterOpenGLInit method.
	 */
	virtual ~ThreeDimensionObject() {};
	/**
	 * Here comes openGL code for the object initialization
	 */
	virtual void initAfterOpenGLLoaded() = 0;
	virtual void draw(std::shared_ptr<glm::mat4> modelViewProjectionMatrix) = 0;
};

}
} /* namespace initial3d */
#endif /* THREEDIMENSIONOBJECT_H_ */
