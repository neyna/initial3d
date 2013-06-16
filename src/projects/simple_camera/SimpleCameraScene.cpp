#include "SimpleCameraScene.hpp"

namespace initial3d {
namespace projects {
namespace simplecamera {

SimpleCameraScene::SimpleCameraScene() {
	simpleTetrahedron = NULL;
}

SimpleCameraScene::~SimpleCameraScene() {
	if(simpleTetrahedron != NULL) {
		delete simpleTetrahedron;
	}
}

void SimpleCameraScene::draw() {
	simpleTetrahedron->draw(camera->getViewProjectionMatrix());
}

void SimpleCameraScene::initAfterOpenGLLoaded() {
	simpleTetrahedron = new Tetrahedron();
}

}
}
} /* namespace initial3d */
