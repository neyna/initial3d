#include "SphericalCameraControlHandler.hpp"

namespace initial3d {
namespace control {

SphericalCameraControlHandler::SphericalCameraControlHandler(SphericalCamera *sphericalCamera) : sphericalCamera(sphericalCamera) {
}

SphericalCameraControlHandler::~SphericalCameraControlHandler() {
}

void SphericalCameraControlHandler::keyPressed(KeyCode keyCode) {
	// TODO speed should increase when we got farther from the lookingPoint of the camera
	const float speed = 5;
	switch (keyCode) {
	case KEY_RIGHT:
		sphericalCamera->startMoving(SphericalCamera::Direction::RIGHT, speed);
		break;
	case KEY_LEFT:
		sphericalCamera->startMoving(SphericalCamera::Direction::LEFT, speed);
		break;
	case KEY_UP:
		sphericalCamera->startMoving(SphericalCamera::Direction::UP, speed);
		break;
	case KEY_DOWN:
		sphericalCamera->startMoving(SphericalCamera::Direction::DOWN, speed);
		break;
	default:
		break;
	}
}

void SphericalCameraControlHandler::keyReleased(KeyCode keyCode) {
	switch (keyCode) {
		case KEY_RIGHT:
			sphericalCamera->stopMoving(SphericalCamera::Direction::RIGHT);
			break;
		case KEY_LEFT:
			sphericalCamera->stopMoving(SphericalCamera::Direction::LEFT);
			break;
		case KEY_UP:
			sphericalCamera->stopMoving(SphericalCamera::Direction::UP);
			break;
		case KEY_DOWN:
			sphericalCamera->stopMoving(SphericalCamera::Direction::DOWN);
			break;
		default:
			break;
		}
}

} /* namespace control */
} /* namespace initial3d */
