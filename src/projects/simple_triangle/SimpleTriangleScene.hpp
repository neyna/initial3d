#ifndef SIMPLETRIANGLESCENE_H_
#define SIMPLETRIANGLESCENE_H_

#include <initial3d.hpp>

using namespace initial3d::scene;
using initial3d::objects::ThreeDimensionsObject;

namespace initial3d {
namespace projects {
namespace simpletriangle {

class SimpleTriangleScene : public Scene {
public:
	SimpleTriangleScene();
	virtual ~SimpleTriangleScene();
private:
	std::shared_ptr<ThreeDimensionsObject> simpleTriangle;
};

}
}
} /* namespace initial3d */
#endif /* SIMPLETRIANGLESCENE_H_ */
