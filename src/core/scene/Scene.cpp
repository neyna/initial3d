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

void Scene::draw() {
	throw "Should never get here because this is an abstract class.";
}

void Scene::computeNextFrame() {

}

void Scene::initAfterOpenGLLoaded() {

}

shared_ptr<Camera> Scene::getCamera() {
	return camera;
}

void Scene::setCamera(shared_ptr<Camera> &camera) {
	this->camera = camera;
}

}
} /* namespace initial3d */
