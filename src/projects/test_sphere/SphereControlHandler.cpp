#include "SphereControlHandler.hpp"

namespace initial3d {
namespace testsphere {

SphereControlHandler::SphereControlHandler(Sphere *sphere, ScenePtr scene) : sphere(sphere), scene(scene) {
}

SphereControlHandler::~SphereControlHandler() {

}

void SphereControlHandler::keyPressed(KeyCode keyCode) {
	switch(keyCode) {
		case KEY_87: //W
			scene->toggleWireFrameRendering();
			break;
		case KEY_MINUS:
			if(actualNumberOfSubdivision==0) {
				break;
			}
			sphere->changeNumberOfSubdivision(--actualNumberOfSubdivision);
			break;
		case KEY_PLUS:
			sphere->changeNumberOfSubdivision(++actualNumberOfSubdivision);
			break;
		default:
			break;
		}
}

void SphereControlHandler::keyReleased(KeyCode keyCode) {
}

} /* namespace testsphere */
} /* namespace initial3d */
