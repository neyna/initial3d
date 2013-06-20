#include "../initial3d.hpp"

namespace initial3d {
namespace system {

Launcher::Launcher(ScenePtr &scene) {
	this->scene = scene;
	this->windowPropertiesPtr = WindowPropertiesPtr(new WindowProperties());
}

Launcher::~Launcher() {
}

Launcher::Launcher(ScenePtr &scene, WindowPropertiesPtr &windowProperties) {
	this->scene = scene;
	this->windowPropertiesPtr = windowProperties;
}

int Launcher::run() {
	throw "Should never get here because this is an abstract class.";
}

} /* namespace system */
} /* namespace initial3d */
