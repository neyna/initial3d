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
}

SimpleCameraScene::~SimpleCameraScene() {
}

void SimpleCameraScene::draw() {
	camera->update();
	std::shared_ptr<glm::mat4> viewProjectionMatrix = camera->getViewProjectionMatrix();
	simpleTetrahedronPtr->draw(viewProjectionMatrix);
}

void SimpleCameraScene::initAfterOpenGLLoaded() {
	simpleTetrahedronPtr->initAfterOpenGLLoaded();
}

void SimpleCameraScene::keyPressed(KeyCode keyCode) {
	// TODO unitsToMove should increase when we got farther from the center
	const float unitsToMove = 0.5;
	SphereRunningCamera *sphereRunningCamera = (SphereRunningCamera*) (camera.get());
	switch(keyCode) {
	case KEY_SPACE:
		sphereRunningCamera->stopRotation();
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
	SphereRunningCamera *sphereRunningCamera = (SphereRunningCamera*) (camera.get());
		switch(keyCode) {
		case KEY_65: //A
			sphereRunningCamera->continueRotation();
			break;
		default:
			break;
		}
}

}
}
} /* namespace initial3d */
