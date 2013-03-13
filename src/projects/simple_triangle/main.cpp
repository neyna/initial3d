#include "../../all_includes.hpp"
#include "SimpleTriangleScene.hpp"

using namespace initial3d;
using namespace log4cxx;
using namespace log4cxx::helpers;

LoggerPtr logger(Logger::getLogger("SimpleTriangleMain"));

int main(void) {

	LOG4CXX_INFO(logger, "Entering application.");
	Scene *scene = new SimpleTriangleScene();
	Launcher *launcher = new GLFWLauncher(scene);

	return launcher->run();
}






