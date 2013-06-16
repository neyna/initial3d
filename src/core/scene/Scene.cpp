#include "../initial3d.hpp"

namespace initial3d {
namespace scene {

Scene::Scene() : camera(new Camera()) {
}

Scene::~Scene() {
}

void Scene::draw() {
	throw "Should never get here because this is an abstract class.";
}

void Scene::computeNextFrame() {

}

void Scene::initAfterOpenGLLoaded() {

}

const Camera* Scene::getCamera() const {
	return camera;
}

void Scene::setCamera(Camera* camera) {
	this->camera = camera;
}

}
} /* namespace initial3d */
