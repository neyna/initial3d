#include <initial3d.hpp>
#include "SimpleCameraScene.hpp"

using namespace initial3d;
using namespace initial3d::exception;
using namespace initial3d::scene;
using namespace initial3d::system;
using namespace initial3d::projects::simplecamera;

using namespace log4cxx;
using namespace std;

LoggerPtr logger(Logger::getLogger("initial3d.projects.simplecamera.main"));

void computeWindowTitle(stringPtr &windowTitle) {
	stringPtr softwareVersion;
	getVersion(softwareVersion);
	stringstream stringstream;
	stringstream << "Simple camera v" << *softwareVersion.get();
	windowTitle.reset(new string(stringstream.str()));
}

int main(void) {

	LOG4CXX_INFO(logger, "Controls :");
	LOG4CXX_INFO(logger, "Esc to exit / P to pause");

	LOG4CXX_INFO(logger, "Entering application.");
	ScenePtr scene = ScenePtr(new SimpleCameraScene());

	stringPtr windowTitle;
	computeWindowTitle(windowTitle);
	WindowPropertiesPtr windowProperties = WindowPropertiesPtr(new WindowProperties(320, 240, windowTitle));
	LauncherPtr launcher = LauncherPtr(new GLFWLauncher(scene, windowProperties));

	try {
		return launcher->run();
	} catch(Initial3dException &e) {
		LOG4CXX_FATAL(logger, std::string(e.getMessage()));
		return -1;
	}
}




