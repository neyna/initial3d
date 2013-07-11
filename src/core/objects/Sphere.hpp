#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../initial3d_basics.hpp"
#include "ThreeDimensionsObject.hpp"

namespace initial3d {
namespace objects {

class Sphere : ThreeDimensionsObject {
public:
	Sphere();
	virtual ~Sphere();
protected:
	float radius;
};

} /* namespace objects */
} /* namespace initial3d */
#endif /* SPHERE_HPP_ */
