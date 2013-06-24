#include "SphereRunningCamera.hpp"
#include "SimpleCameraScene.hpp"

using namespace std;
using namespace initial3d::system;
using namespace glm;

namespace initial3d {
namespace projects {
namespace simplecamera {

SimpleCameraScene::SimpleCameraScene() : Scene(shared_ptr<Camera>(new SphereRunningCamera())) {
}

SimpleCameraScene::~SimpleCameraScene() {
}

void SimpleCameraScene::draw() {
	camera->update();
	simpleTetrahedronPtr->draw(camera->getViewProjectionMatrix());
}

void SimpleCameraScene::initAfterOpenGLLoaded() {
	simpleTetrahedronPtr.reset(new Tetrahedron());
}

}
}
} /* namespace initial3d */
