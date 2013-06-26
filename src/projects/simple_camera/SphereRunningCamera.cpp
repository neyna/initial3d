#include <initial3d.hpp>
#include "SphereRunningCamera.hpp"

using glm::vec3;
using namespace initial3d::system;

namespace initial3d {
namespace projects {
namespace simplecamera {


SphereRunningCamera::SphereRunningCamera(const vec3 &initialPosition, const vec3 &lookAtPoint, double zAngularSpeed, double xAngularSpeed) :
		SphericalCamera(initialPosition, lookAtPoint), zAngularSpeed(zAngularSpeed), xAngularSpeed(xAngularSpeed) {
	currentTime = getTime();
}

void SphereRunningCamera::update() {
	double newTime = getTime();
	double deltaTime = newTime - currentTime;

	if( ! (deltaTime)>0 ) {
		return;
	}

	theta += zAngularSpeed * deltaTime;
	phi += xAngularSpeed * deltaTime;

	currentTime = newTime;

	vec3 position(radius * sin(theta)*cos(phi),
			radius * sin(theta)*sin(phi),
			radius * cos(theta));
	// computing up vector, we will use the direction
	vec3 up = position - this->position;
	// update new position
	this->position = position;

	this->lookAt(position, lookAtPoint, up);
}

SphereRunningCamera::~SphereRunningCamera() {

}

} /* namespace simplecamera */
} /* namespace projects */
} /* namespace initial3d */
