#include "../initial3d.hpp"

using namespace std;

namespace initial3d {
namespace scene {

Scene::Scene() : camera(new Camera()) {
}

Scene::Scene(std::shared_ptr<Camera> camera) : camera(camera) {
}

Scene::~Scene() {
	this->camera = NULL;
}

void Scene::computeNextFrame() {

}

/**
 * Call initAfterOpenGLLoaded on each object
 */
void Scene::initAfterOpenGLLoaded() {
	for (ThreeDimensionObjectPtr threeDimensionObjectPtr : threeDimensionsObjects) {
		threeDimensionObjectPtr->initAfterOpenGLLoaded();
	}
}

shared_ptr<Camera> Scene::getCamera() {
	return camera;
}

void Scene::setCamera(shared_ptr<Camera> &camera) {
	this->camera = camera;
}

void Scene::keyPressed(KeyCode keyCode) {
}

void Scene::addObject(ThreeDimensionObjectPtr &threeDimensionObjectPtr) {
	threeDimensionsObjects.push_back(threeDimensionObjectPtr);
}

void Scene::draw() {
	camera->update();
	std::shared_ptr<glm::mat4> viewProjectionMatrix = camera->getViewProjectionMatrix();

	// TODO : compute modelViewProjectionMatrix for each object
	for (ThreeDimensionObjectPtr threeDimensionObjectPtr : threeDimensionsObjects) {
		threeDimensionObjectPtr->draw(viewProjectionMatrix);
	}
}

void Scene::keyReleased(KeyCode keyCode) {
}

}
} /* namespace initial3d */
