#include "../initial3d.hpp"

namespace initial3d {
namespace scene {

Scene::Scene() {
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

}
} /* namespace initial3d */
