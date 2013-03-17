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
	simpleTriangle->draw();
}

void SimpleTriangleScene::initAfterOpenGLLoaded() {
	simpleTriangle = new SimpleTriangle();
}

}
}
} /* namespace initial3d */
