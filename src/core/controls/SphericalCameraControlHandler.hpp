#ifndef SPHERICALCAMERAKEYHANDLER_HPP_
#define SPHERICALCAMERAKEYHANDLER_HPP_

#include "ControlHandler.hpp"
#include "../scene/SphericalCamera.hpp"

using initial3d::scene::SphericalCamera;

namespace initial3d {
namespace control {

class SphericalCameraControlHandler : public ControlHandler {
public:
	SphericalCameraControlHandler(SphericalCamera *sphericalCamera);
	virtual ~SphericalCameraControlHandler();
	virtual void keyPressed(KeyCode keyCode);
	virtual void keyReleased(KeyCode keyCode);
protected:
	SphericalCamera *sphericalCamera = nullptr;
};

} /* namespace control */
} /* namespace initial3d */
#endif /* SPHERICALCAMERAKEYHANDLER_HPP_ */
