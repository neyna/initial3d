#include "SphereRunningCamera.hpp"
#include "SimpleCameraScene.hpp"

using namespace std;
using namespace initial3d::system;
using namespace glm;

namespace initial3d {
namespace projects {
namespace simplecamera {

SimpleCameraScene::SimpleCameraScene() : Scene(shared_ptr<Camera>(new SphereRunningCamera())),
		simpleTetrahedronPtr(new Tetrahedron()){
	SphereRunningCamera *sphereRunningCamera = (SphereRunningCamera*) (camera.get());
	sphereRunningCamera->horizontalSpeed = 0.1f;
	sphereRunningCamera->vecticalSpeed = -0.1f;

	addObject(simpleTetrahedronPtr);
}

SimpleCameraScene::~SimpleCameraScene() {
}

void SimpleCameraScene::keyPressed(KeyCode keyCode) {
	// TODO unitsToMove should increase when we got farther from the center
	const float unitsToMove = 0.5;
	SphereRunningCamera *sphereRunningCamera = (SphereRunningCamera*) (camera.get());
	switch(keyCode) {
	case KEY_SPACE:
		sphereRunningCamera->stopRotation();
		break;
	case KEY_65: //A
		sphereRunningCamera->continueRotation();
		break;
	case KEY_66: //B
		setWireFrameRendering(true);
		break;
	case KEY_RIGHT:
		sphereRunningCamera->moveRight(unitsToMove);
		break;
	case KEY_LEFT:
		sphereRunningCamera->moveLeft(unitsToMove);
		break;
	case KEY_UP:
		sphereRunningCamera->moveUp(unitsToMove);
		break;
	case KEY_DOWN:
		sphereRunningCamera->moveDown(unitsToMove);
		break;
	default:
		break;
	}
}

void SimpleCameraScene::keyReleased(KeyCode keyCode) {
		switch(keyCode) {
		default:
			break;
		}
}

}
}
} /* namespace initial3d */
