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
	static log4cxx::LoggerPtr logger;
	/**
	 * horizontalSpeed : speed to the right of the camera
	 * vecticalSpeed : speed to the up of the camera
	 */
	SphereRunningCamera(const glm::vec3 &initialPosition = glm::vec3(4,3,3),
			const glm::vec3 &lookAtPoint = glm::vec3(0,0,0), const glm::vec3 &up = glm::vec3(0,0,1),
			double vecticalSpeed = 0.1f, double horizontalSpeed = -0.1f);
	virtual ~SphereRunningCamera();
	virtual void update();

	void stopRotation();
	void continueRotation();

	double vecticalSpeed;
	double horizontalSpeed;
protected:
	double currentTime = 0.0f;
	bool isMoving = false;
};

} /* namespace simplecamera */
} /* namespace projects */
} /* namespace initial3d */
#endif /* SPHERERUNNINGCAMERA_HPP_ */
