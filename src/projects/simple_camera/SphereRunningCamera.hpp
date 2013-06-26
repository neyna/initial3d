#ifndef SPHERERUNNINGCAMERA_HPP_
#define SPHERERUNNINGCAMERA_HPP_

#include <initial3d.hpp>

namespace initial3d {
namespace projects {
namespace simplecamera {

/**
 * Camera that turns around a center point
 * It will run through the entire sphere surface looking at center point
 */
class SphereRunningCamera : public SphericalCamera {
public:
	SphereRunningCamera(const glm::vec3 &initialPosition = glm::vec3(4,3,3), const glm::vec3 &lookAtPoint = glm::vec3(0,0,0),
			double zAngularSpeed = 0.3f, double xAngularSpeed = -0.3f);
	virtual ~SphereRunningCamera();
	virtual void update();
protected:
	double currentTime = 0.0f;
	/**
	 * Angular speed around the Z-Axis in rad.s^-1
	 */
	double zAngularSpeed;
	/**
	 * Angular speed around the X-Axis in rad.s^-1
	 */
	double xAngularSpeed;
};

} /* namespace simplecamera */
} /* namespace projects */
} /* namespace initial3d */
#endif /* SPHERERUNNINGCAMERA_HPP_ */
