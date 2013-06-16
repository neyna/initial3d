#ifndef SIMPLETRIANGLESCENE_H_
#define SIMPLETRIANGLESCENE_H_

#include <initial3d.hpp>
#include "SimpleTetrahedron.hpp"

using namespace initial3d::scene;

namespace initial3d {
namespace projects {
namespace simplecamera {

class SimpleCameraScene : public Scene {
public:
	SimpleCameraScene();
	virtual ~SimpleCameraScene();
	virtual void initAfterOpenGLLoaded();
	virtual void draw();
private:
	Tetrahedron *simpleTetrahedron;
};

}
}
} /* namespace initial3d */
#endif /* SIMPLETRIANGLESCENE_H_ */
