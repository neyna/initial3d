#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../initial3d_basics.hpp"
#include "ThreeDimensionsObject.hpp"

namespace initial3d {
namespace objects {

/**
 * Sphere object.
 * Build a sphere using the following algorithm : http://stackoverflow.com/questions/7687148/drawing-sphere-in-opengl-without-using-glusphere
 *
 * TODO : generate lot of different level of detail and draw if according to the distance to the camera
 * TODO : the sphere must store all computation relative to the numberOfSubdivision
 */
class Sphere : public ThreeDimensionsObject {
public:
	// c++11 feature, gets all base object constructors, needs gcc 4.8+ to work :(
	//using ThreeDimensionsObject::ThreeDimensionsObject;
	Sphere(float radius = 1.0f);
	virtual ~Sphere();

	virtual void draw(std::shared_ptr<glm::mat4> &modelViewProjectionMatrix);
protected:
	float radius = 1.0f;
	std::vector<glm::vec3> data = std::vector<glm::vec3>(0);
	std::shared_ptr<std::vector<GLfloat> > glData;
	/**
	 * Number of recursive subdivision after having built the octahedron
	 */
	int numberOfSubdivision = 0;
};

typedef std::shared_ptr<Sphere> SpherePtr;

} /* namespace objects */
} /* namespace initial3d */
#endif /* SPHERE_HPP_ */