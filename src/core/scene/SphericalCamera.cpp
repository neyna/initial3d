#include "../initial3d.hpp"

using glm::cross;
using glm::normalize;
using glm::length;
using glm::vec3;

using log4cxx::LoggerPtr;
using log4cxx::Logger;
using boost::format;

namespace initial3d {
namespace scene {

LoggerPtr SphericalCamera::logger = LoggerPtr(Logger::getLogger("initial3d.scene.SphericalCamera"));

SphericalCamera::SphericalCamera(const glm::vec3 &initialPosition, const glm::vec3 &lookAtPoint, const glm::vec3 &up)
	: position(initialPosition), lookAtPoint(lookAtPoint), up(up) {
	// compute radius
	radius = sqrt(
			pow(initialPosition.x - lookAtPoint.x, 2)
					+ pow(initialPosition.y - lookAtPoint.y, 2)
					+ pow(initialPosition.z - lookAtPoint.z, 2));

}

SphericalCamera::~SphericalCamera() {

}

void SphericalCamera::moveUp(double unitsToMove) {
	vec3 rightVector = normalize(cross(lookAtPoint - position, up));
	// compute new position which will not be on the sphere
	vec3 newPositionNotOnSphere = position + (up * vec3(unitsToMove));
	vec3 lookAtVector = lookAtPoint - newPositionNotOnSphere;
	double lookAtVectorLength = length(lookAtVector);
	// comute new position
	this->position = lookAtPoint - (lookAtVector * vec3(radius / lookAtVectorLength));

	// compute new up vector
	this->up = normalize(cross(rightVector, lookAtVector));
}

void SphericalCamera::moveDown(double unitsToMove) {
	moveUp(-unitsToMove);
}

/**
 * horizontalVector must be normalized
 */
void SphericalCamera::horizontalMove(const vec3& horizontalVector, double unitsToMove) {
	// compute new position which will not be on the sphere
	vec3 newPositionNotOnSphere = position + (horizontalVector * vec3(unitsToMove));
	// we need to adjust the distance to the center of the sphere
	// multiplying each coordinate by a scalar will multiply the norm by the absolute value of the same scalar
	// ||a*v|| = sqrt( a*a*vx*vx + a*a**vy*vy + a*a*vz*vz ) = |a| * ||v||
	vec3 lookAtVector = lookAtPoint - newPositionNotOnSphere;
	double lookAtVectorLength = length(lookAtVector);
	this->position = lookAtPoint - (lookAtVector * vec3(radius / lookAtVectorLength));
}

void SphericalCamera::moveRight(double unitsToMove) {
	vec3 rightVector = normalize(cross(lookAtPoint - position, up));
	horizontalMove(rightVector, unitsToMove);
}

void SphericalCamera::moveLeft(double unitsToMove) {
	moveRight(-unitsToMove);
}

} /* namespace projects */
} /* namespace initial3d */
