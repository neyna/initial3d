#include "SphericalCameraControlHandler.hpp"

namespace initial3d {
namespace control {

SphericalCameraControlHandler::SphericalCameraControlHandler(SphericalCamera *sphericalCamera) : sphericalCamera(sphericalCamera) {
}

SphericalCameraControlHandler::~SphericalCameraControlHandler() {
}

void SphericalCameraControlHandler::keyPressed(KeyCode keyCode) {
	// TODO unitsToMove should increase when we got farther from the lookingPoint of the camera
	const float unitsToMove = 0.5;
	switch (keyCode) {
	case KEY_RIGHT:
		sphericalCamera->moveRight(unitsToMove);
		break;
	case KEY_LEFT:
		sphericalCamera->moveLeft(unitsToMove);
		break;
	case KEY_UP:
		sphericalCamera->moveUp(unitsToMove);
		break;
	case KEY_DOWN:
		sphericalCamera->moveDown(unitsToMove);
		break;
	default:
		break;
	}
}

void SphericalCameraControlHandler::keyReleased(KeyCode keyCode) {
}

} /* namespace control */
} /* namespace initial3d */
