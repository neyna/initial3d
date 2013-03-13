#include "SimpleTriangleScene.hpp"

namespace initial3d {
namespace projects {
namespace simpletriangle {

SimpleTriangleScene::SimpleTriangleScene() {
	firstTriangle = NULL;
}

SimpleTriangleScene::~SimpleTriangleScene() {
	if(firstTriangle != NULL) {
		delete firstTriangle;
	}
}

void SimpleTriangleScene::draw() {
	firstTriangle->draw();
}

void SimpleTriangleScene::initAfterOpenGLLoaded() {
	firstTriangle = new FirstTriangle();
}

}
}
} /* namespace initial3d */
