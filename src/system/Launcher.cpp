#include "../all_includes.hpp"

namespace initial3d {

Launcher::Launcher(Scene *scene) {
	this->scene = scene;
}

Launcher::~Launcher() {
}

int Launcher::run() {
	throw "Should never get here because this is an abstract class.";
}

} /* namespace initial3d */
