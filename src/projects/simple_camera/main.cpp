#include <initial3d.hpp>
#include "SimpleCameraScene.hpp"

using namespace initial3d::exception;
using namespace initial3d::scene;
using namespace initial3d::system;
using namespace initial3d::projects::simplecamera;

using namespace log4cxx;

LoggerPtr logger(Logger::getLogger("initial3d.projects.simplecamera.main"));

string computeWindowTitle() {
	char* softwareVersion = getVersion();
	std::stringstream stringstream;
	stringstream << "Simple camera v" << softwareVersion;
	free(softwareVersion);
	return stringstream.str();
}

int main(void) {

	LOG4CXX_INFO(logger, "Entering application.");
	Scene *scene = new SimpleCameraScene();

	string windowTitle = computeWindowTitle();
	WindowProperties *windowProperties = new WindowProperties(320, 240, &windowTitle);
	Launcher *launcher = new GLFWLauncher(scene, windowProperties);

	try {
		return launcher->run();
	} catch(Initial3dException &e) {
		LOG4CXX_FATAL(logger, std::string(e.getMessage()));
		return -1;
	}
	delete scene;
	delete launcher;
}




