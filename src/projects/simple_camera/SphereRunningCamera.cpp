#include <initial3d.hpp>
#include "SphereRunningCamera.hpp"

using glm::vec3;
using namespace initial3d::system;

namespace initial3d {
namespace projects {
namespace simplecamera {


SphereRunningCamera::SphereRunningCamera(const vec3 &initialPosition, const vec3 &lookAtPoint) :
		lookAtPoint(lookAtPoint), position(initialPosition), zAngularSpeed(0.3f), xAngularSpeed(-0.3f) {

	currentTime = getTime();

	// compute radius
	radius = sqrt(
					pow(initialPosition.x - lookAtPoint.x, 2)
					+ pow(initialPosition.y - lookAtPoint.y, 2)
					+ pow(initialPosition.z - lookAtPoint.z, 2));

	// compute theta and phi using formulae
	// (1) x = radius * sin(theta)*cos(phi)
	// (2) y = radius * sin(theta)*sin(phi)
	// (3) z = radius * cos(theta)

	// using (3)
	theta = acos(position.z / radius);
	// using (1)
	// todo if sin(theta = 0)
	phi = acos( ( position.x / radius ) / sin(theta));
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
