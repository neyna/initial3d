#include "../../all_includes.hpp"
#include "SimpleTriangleScene.hpp"

using namespace initial3d::scene;
using namespace initial3d::system;
using namespace initial3d::projects::simpletriangle;

using namespace log4cxx;

LoggerPtr logger(Logger::getLogger("initial3d.projects.simpletriangle.main"));

int main(void) {

	LOG4CXX_INFO(logger, "Entering application.");
	Scene *scene = new SimpleTriangleScene();
	Launcher *launcher = new GLFWLauncher(scene);

	return launcher->run();
}




