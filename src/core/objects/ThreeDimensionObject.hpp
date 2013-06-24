#ifndef THREEDIMENSIONOBJECT_H_
#define THREEDIMENSIONOBJECT_H_

namespace initial3d {
namespace objects {

class ThreeDimensionObject {
public:
	virtual ~ThreeDimensionObject() {};
	virtual void draw(std::shared_ptr<glm::mat4> modelViewProjectionMatrix) = 0;
};

}
} /* namespace initial3d */
#endif /* THREEDIMENSIONOBJECT_H_ */
