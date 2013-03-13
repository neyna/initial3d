#include "../all_includes.hpp"

namespace initial3d {
namespace system {

Launcher::Launcher(Scene *scene) {
	this->scene = scene;
}

Launcher::~Launcher() {
}

int Launcher::run() {
	throw "Should never get here because this is an abstract class.";
}

} /* namespace system */
} /* namespace initial3d */
