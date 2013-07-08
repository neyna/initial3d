#include "../initial3d.hpp"

using namespace std;

namespace initial3d {
namespace scene {

Scene::Scene() : camera(new Camera()), wireframeRendering(false) {
}

Scene::Scene(std::shared_ptr<Camera> camera) : camera(camera), wireframeRendering(false) {
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

	initRendering();

	// draw objects
	// TODO : compute modelViewProjectionMatrix for each object
	for (ThreeDimensionObjectPtr threeDimensionObjectPtr : threeDimensionsObjects) {
		threeDimensionObjectPtr->draw(viewProjectionMatrix);
	}
}

void Scene::keyReleased(KeyCode keyCode) {
}

void Scene::setWireFrameRendering(bool status) {
	this->wireframeRendering = status;
}

void Scene::initRendering() {
	// Dark background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT GL_STENCIL_BUFFER_BIT

	if(wireframeRendering) {
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	} else {
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
	}
}

}
} /* namespace initial3d */
