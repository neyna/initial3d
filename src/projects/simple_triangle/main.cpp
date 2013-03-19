#include <initial3d.hpp>
#include "SimpleTriangleScene.hpp"

using namespace initial3d::exception;
using namespace initial3d::scene;
using namespace initial3d::system;
using namespace initial3d::projects::simpletriangle;

using namespace log4cxx;

LoggerPtr logger(Logger::getLogger("initial3d.projects.simpletriangle.main"));

int main(void) {

	LOG4CXX_INFO(logger, "Entering application.");
	Scene *scene = new SimpleTriangleScene();
	Launcher *launcher = new GLFWLauncher(scene);

	try {
		return launcher->run();
	} catch(Initial3dException &e) {
		LOG4CXX_FATAL(logger, std::string(e.getMessage()));
		return -1;
	}
}




