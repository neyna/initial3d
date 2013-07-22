#ifndef SPHERICALCAMERA_HPP_
#define SPHERICALCAMERA_HPP_

#include "../initial3d_basics.hpp"
#include "Camera.hpp"

namespace initial3d {
namespace scene {

/**
 * Camera that rotates around a center point
 */
class SphericalCamera : public Camera {
public:
	SphericalCamera(const glm::vec3 &initialPosition = glm::vec3(4,3,3), const glm::vec3 &lookAtPoint = glm::vec3(0,0,0),
			const glm::vec3 &up = glm::vec3(0,0,1));
	virtual ~SphericalCamera();
	void moveRight(double unitsToMove);
	void moveLeft(double unitsToMove);
	void moveUp(double unitsToMove);
	void moveDown(double unitsToMove);
	virtual void update();
protected:
	static log4cxx::LoggerPtr logger;
	/**
	 * Position of the camera
	 */
	glm::vec3 position;
	/**
	 * Position to which the camera is looking at. I.e. center of the sphere
	 */
	glm::vec3 lookAtPoint;
	/**
	 * Up vector for the camera
	 */
	glm::vec3 up;

	double radius;
private:
	void horizontalMove(const glm::vec3& rightVector, double distance);
};

} /* namespace scene */
} /* namespace initial3d */
#endif /* SPHERICALCAMERA_HPP_ */
