#ifndef SIMPLETRIANGLESCENE_H_
#define SIMPLETRIANGLESCENE_H_

#include "../../all_includes.hpp"
#include "FirstTriangle.hpp"

namespace initial3d {

class SimpleTriangleScene : public Scene {
public:
	SimpleTriangleScene();
	virtual ~SimpleTriangleScene();
	virtual void initAfterOpenGLLoaded();
	virtual void draw();
private:
	FirstTriangle *firstTriangle;
};

} /* namespace initial3d */
#endif /* SIMPLETRIANGLESCENE_H_ */
