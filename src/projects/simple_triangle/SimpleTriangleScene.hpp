#ifndef SIMPLETRIANGLESCENE_H_
#define SIMPLETRIANGLESCENE_H_

#include "../../all_includes.hpp"
#include "FirstTriangle.hpp"

using namespace initial3d::scene;

namespace initial3d {
namespace projects {
namespace simpletriangle {

class SimpleTriangleScene : public Scene {
public:
	SimpleTriangleScene();
	virtual ~SimpleTriangleScene();
	virtual void initAfterOpenGLLoaded();
	virtual void draw();
private:
	FirstTriangle *firstTriangle;
};

}
}
} /* namespace initial3d */
#endif /* SIMPLETRIANGLESCENE_H_ */
