#ifndef SPHERECONTROLHANDLER_HPP_
#define SPHERECONTROLHANDLER_HPP_

#include <initial3d.hpp>

using initial3d::control::ControlHandler;
using initial3d::objects::Sphere;

namespace initial3d {
namespace testsphere {

class SphereControlHandler : public ControlHandler {
public:
	SphereControlHandler(Sphere *sphere, ScenePtr scene);
	virtual ~SphereControlHandler();
	virtual void keyPressed(KeyCode keyCode);
	virtual void keyReleased(KeyCode keyCode);
protected:
	Sphere *sphere;
	ScenePtr scene;
	int actualNumberOfSubdivision = 0;
};

} /* namespace testsphere */
} /* namespace initial3d */
#endif /* SPHERECONTROLHANDLER_HPP_ */
