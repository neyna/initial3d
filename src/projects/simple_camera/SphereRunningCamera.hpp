#ifndef SPHERERUNNINGCAMERA_HPP_
#define SPHERERUNNINGCAMERA_HPP_

#include <initial3d.hpp>

namespace initial3d {
namespace projects {
namespace simplecamera {

/**
 * Camera that turns around a center point
 * It will run through the entire sphere surface looking at center point
 *
 * We use a spherical coordinates system (the physical one). It means theta is the angle around the Z-Axis
 * and that phi is the one around the X-Axis. In such system we have :
 * x = radius * sin(theta)*cos(phi)
 * y = radius * sin(theta)*sin(phi)
 * z = radius * cos(theta)
 *
 * @See : https://fr.wikipedia.org/wiki/Coordonnées_polaires
 */
class SphereRunningCamera : public Camera {
public:
	SphereRunningCamera(const glm::vec3 &initialPosition = glm::vec3(4,3,3), const glm::vec3 &lookAtPoint = glm::vec3(0,0,0));
	virtual ~SphereRunningCamera();
	virtual void update();
protected:
	double currentTime = 0.0f;
	/**
	 * Position to which the camera is looking at
	 */
	glm::vec3 lookAtPoint;
	/**
	 * Position of the camera
	 */
	glm::vec3 position;
	double radius;
	/**
	 * Angular speed around the Z-Axis in rad.s^-1
	 */
	double zAngularSpeed;
	/**
	 * Angle around the Z-Axis
	 */
	double theta;
	/**
	 * Angular speed around the X-Axis in rad.s^-1
	 */
	double xAngularSpeed;
	/**
	 * Angle around the X-Axis
	 */
	double phi;
};

} /* namespace simplecamera */
} /* namespace projects */
} /* namespace initial3d */
#endif /* SPHERERUNNINGCAMERA_HPP_ */
