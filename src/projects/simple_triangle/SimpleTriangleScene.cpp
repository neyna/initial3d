#include "SimpleTriangleScene.hpp"

namespace initial3d {
namespace projects {
namespace simpletriangle {

SimpleTriangleScene::SimpleTriangleScene() : simpleTriangle(std::shared_ptr<ThreeDimensionsObject>(new SimpleTriangle())) {
	addObject(simpleTriangle);
}

SimpleTriangleScene::~SimpleTriangleScene() {
}

}
}
} /* namespace initial3d */
