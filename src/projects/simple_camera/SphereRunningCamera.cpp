#include <initial3d.hpp>
#include "SphereRunningCamera.hpp"

using log4cxx::LoggerPtr;
using log4cxx::Logger;
using glm::vec3;
using boost::format;
using namespace initial3d::system;

namespace initial3d {
namespace projects {
namespace simplecamera {

LoggerPtr SphereRunningCamera::logger = LoggerPtr(Logger::getLogger("initial3d.projects.simplecamera.SphereRunningCamera"));


SphereRunningCamera::SphereRunningCamera(const vec3 &initialPosition, const vec3 &lookAtPoint, const glm::vec3 &up, double vecticalSpeed, double horizontalSpeed) :
		SphericalCamera(initialPosition, lookAtPoint, up), vecticalSpeed(vecticalSpeed), horizontalSpeed(horizontalSpeed) {
	updateMovement();
}

SphereRunningCamera::~SphereRunningCamera() {
}

void SphereRunningCamera::updateMovement() {
	if (isRotating) {
		this->startMoving(SphericalCamera::Direction::RIGHT, horizontalSpeed);
		this->startMoving(SphericalCamera::Direction::UP, vecticalSpeed);
	} else {
		this->stopMoving(SphericalCamera::Direction::RIGHT);
		this->stopMoving(SphericalCamera::Direction::UP);
	}
}

void SphereRunningCamera::setRotating(bool rotating) {
	isRotating = rotating;
	updateMovement();
}

} /* namespace simplecamera */
} /* namespace projects */
} /* namespace initial3d */
