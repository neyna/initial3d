#include "SimpleTriangleScene.hpp"

namespace initial3d {
namespace projects {
namespace simpletriangle {

SimpleTriangleScene::SimpleTriangleScene() {
	simpleTriangle = NULL;
}

SimpleTriangleScene::~SimpleTriangleScene() {
	if(simpleTriangle != NULL) {
		delete simpleTriangle;
	}
}

void SimpleTriangleScene::draw() {
	std::shared_ptr<glm::mat4> viewProjectionMatrix = camera->getViewProjectionMatrix();
	simpleTriangle->draw(viewProjectionMatrix);
}

void SimpleTriangleScene::initAfterOpenGLLoaded() {
	simpleTriangle = new SimpleTriangle();
}

}
}
} /* namespace initial3d */
