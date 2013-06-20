#include "SimpleCameraScene.hpp"

using namespace initial3d::system;

namespace initial3d {
namespace projects {
namespace simplecamera {

SimpleCameraScene::SimpleCameraScene() {
	simpleTetrahedron = NULL;
}

SimpleCameraScene::~SimpleCameraScene() {
	if(simpleTetrahedron != NULL) {
		delete simpleTetrahedron;
	}
}

void SimpleCameraScene::draw() {
	double time0 = getTime();
	// change camera position around a circle
	// speed

	// circle of center (a, b) and radius r :
	// (x-a)² + (y-b)² = r²
	// Or in parametric form where t in [0, 2*pi]
	// x = a+r*cos(t)
    // y = b+r*sin(t)
	// Or another one ;
	// x = a + r*(1-t²)/(1+t²)
	// y = b + r*2*t/(t+t²)



	simpleTetrahedron->draw(camera->getViewProjectionMatrix());
}

void SimpleCameraScene::initAfterOpenGLLoaded() {
	simpleTetrahedron = new Tetrahedron();
}

}
}
} /* namespace initial3d */
