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
		SphericalCamera(initialPosition, lookAtPoint, up), vecticalSpeed(vecticalSpeed), horizontalSpeed(horizontalSpeed), isMoving(true) {
	currentTime = getTime();
}

void SphereRunningCamera::update() {
	double newTime = getTime();
	double deltaTime = newTime - currentTime;
	currentTime = newTime;

	if( ! (deltaTime)>0 ) {
		return;
	}

	if(isMoving) {
		this->moveRight(horizontalSpeed);
		this->moveUp(vecticalSpeed);
	}

	this->lookAt(position, lookAtPoint, up);
}

SphereRunningCamera::~SphereRunningCamera() {

}

void SphereRunningCamera::stopRotation() {
	isMoving = false;
}

void SphereRunningCamera::continueRotation() {
	isMoving = true;
}

} /* namespace simplecamera */
} /* namespace projects */
} /* namespace initial3d */
