#include <initial3d.hpp>

using namespace initial3d::exception;
using namespace initial3d::scene;
using namespace initial3d::system;

using namespace log4cxx;

LoggerPtr logger(Logger::getLogger("initial3d.projects.testsphere.main"));

int main(void) {

	LOG4CXX_INFO(logger, "Entering application.");
	//ScenePtr scene = ScenePtr(new SimpleTriangleScene());
	//LauncherPtr launcher = LauncherPtr(new GLFWLauncher(scene));

	try {
		//return launcher->run();
		return 0;
	} catch(Initial3dException &e) {
		LOG4CXX_FATAL(logger, std::string(e.getMessage()));
		return -1;
	}
}




