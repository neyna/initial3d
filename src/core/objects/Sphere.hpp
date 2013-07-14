#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../initial3d_basics.hpp"
#include "ThreeDimensionsObject.hpp"

namespace initial3d {
namespace objects {

class Sphere : public ThreeDimensionsObject {
public:
	// c++11 feature, gets all base object constructors, needs gcc 4.8+ to work :(
	//using ThreeDimensionsObject::ThreeDimensionsObject;
	Sphere();
	virtual ~Sphere();
protected:
	float radius = 1.0f;
};

typedef std::shared_ptr<Sphere> SpherePtr;

} /* namespace objects */
} /* namespace initial3d */
#endif /* SPHERE_HPP_ */
