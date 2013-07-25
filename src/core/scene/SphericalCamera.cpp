#include "SphericalCamera.hpp"
#include "../system/System.hpp"
#include "../controls/SphericalCameraControlHandler.hpp"

using glm::cross;
using glm::normalize;
using glm::length;
using glm::vec3;

using log4cxx::LoggerPtr;
using log4cxx::Logger;
using boost::format;

using initial3d::system::getTime;
using initial3d::control::SphericalCameraControlHandler;

namespace initial3d {
namespace scene {

LoggerPtr SphericalCamera::logger = LoggerPtr(Logger::getLogger("initial3d.scene.SphericalCamera"));
std::vector<SphericalCamera::Direction> SphericalCamera::ALL_DIRECTIONS = {
		SphericalCamera::Direction::UP, SphericalCamera::Direction::DOWN, SphericalCamera::Direction::LEFT, SphericalCamera::Direction::RIGHT};

SphericalCamera::SphericalCamera(const glm::vec3 &initialPosition, const glm::vec3 &lookAtPoint, const glm::vec3 &up)
	: position(initialPosition), lookAtPoint(lookAtPoint), up(up) {
	// compute radius
	radius = sqrt(
			pow(initialPosition.x - lookAtPoint.x, 2)
					+ pow(initialPosition.y - lookAtPoint.y, 2)
					+ pow(initialPosition.z - lookAtPoint.z, 2));
	lastTime = getTime();

	controlHandlers.push_back(ControlHandlerPtr(new SphericalCameraControlHandler(this)));
}

SphericalCamera::~SphericalCamera() {

}

void SphericalCamera::moveUp(double unitsToMove) {
	vec3 rightVector = normalize(cross(lookAtPoint - position, up));
	// compute new position which will not be on the sphere
	vec3 newPositionNotOnSphere = position + (up * vec3(unitsToMove));
	vec3 lookAtVector = lookAtPoint - newPositionNotOnSphere;
	float lookAtVectorLength = length(lookAtVector);
	// comute new position
	this->position = lookAtPoint - (lookAtVector * (radius / lookAtVectorLength));

	// compute new up vector
	this->up = normalize(cross(rightVector, lookAtVector));
}

void SphericalCamera::moveDown(double unitsToMove) {
	moveUp(-unitsToMove);
}

void SphericalCamera::update() {
	double newTime = getTime();
	double deltaTime = newTime - lastTime;
	lastTime = newTime;

	if(deltaTime > 0) {
		for (SphericalCamera::Direction direction : ALL_DIRECTIONS) {
			move(direction, deltaTime * movingSpeeds[direction]);
		}
	}
	this->lookAt(position, lookAtPoint, up);
}

void SphericalCamera::move(Direction direction, double unitsToMove) {
	switch(direction) {
	case UP:
		moveUp(unitsToMove);
		break;
	case DOWN:
		moveDown(unitsToMove);
		break;
	case LEFT:
		moveLeft(unitsToMove);
		break;
	case RIGHT:
		moveRight(unitsToMove);
		break;
	default:
		break;
	}
}

void SphericalCamera::startMoving(Direction direction, double speed) {
	isMoving = true;
	movingSpeeds[direction] = speed;
}

void SphericalCamera::stopMoving(Direction direction) {
	isMoving = false;
	movingSpeeds[direction] = 0.0f;
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
	float lookAtVectorLength = length(lookAtVector);
	this->position = lookAtPoint - (lookAtVector * (radius / lookAtVectorLength));
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
