#include "../initial3d.hpp"

namespace initial3d {
namespace system {

Launcher::Launcher(Scene *scene) {
	this->scene = scene;
	this->windowProperties = new WindowProperties();
}

Launcher::~Launcher() {
}

Launcher::Launcher(Scene* scene, WindowProperties* windowProperties) {
	this->scene = scene;
	this->windowProperties = windowProperties;
}

int Launcher::run() {
	throw "Should never get here because this is an abstract class.";
}

} /* namespace system */
} /* namespace initial3d */
