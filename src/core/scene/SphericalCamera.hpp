#ifndef SPHERICALCAMERA_HPP_
#define SPHERICALCAMERA_HPP_

#include "../standard_includes.hpp"

namespace initial3d {
namespace scene {

/**
 * Camera that rotates around a center point
 *
 * We use a spherical coordinates system (the physical one). It means theta is the angle around the Z-Axis
 * and that phi is the one around the X-Axis. In such system we have :
 * x = radius * sin(theta)*cos(phi)
 * y = radius * sin(theta)*sin(phi)
 * z = radius * cos(theta)
 *
 * @See : https://fr.wikipedia.org/wiki/Coordonnées_polaires
 */
class SphericalCamera : public Camera {
public:
	SphericalCamera(const glm::vec3 &initialPosition = glm::vec3(4,3,3), const glm::vec3 &lookAtPoint = glm::vec3(0,0,0));
	virtual ~SphericalCamera();
protected:
	/**
	 * Position of the camera
	 */
	glm::vec3 position;
	/**
	 * Position to which the camera is looking at
	 */
	glm::vec3 lookAtPoint;
	double radius;
	/**
	 * Angle around the Z-Axis
	 */
	double theta;
	/**
	 * Angle around the X-Axis
	 */
	double phi;
};

} /* namespace scene */
} /* namespace initial3d */
#endif /* SPHERICALCAMERA_HPP_ */
