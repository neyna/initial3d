#include <initial3d.hpp>
#include "SimpleCameraScene.hpp"

using namespace initial3d;
using namespace initial3d::exception;
using namespace initial3d::scene;
using namespace initial3d::system;
using namespace initial3d::projects::simplecamera;

using initial3d::utils::GameInformations;

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

void generateDisplayInformations() {
	GameInformations::getInstance().getOrCreateGameInformation(
			stringPtr(new string("INSTRUCTIONS_1")),
			stringPtr(new string("Controls : Esc to exit / Space to toggle rotation")));
	GameInformations::getInstance().getOrCreateGameInformation(
			stringPtr(new string("INSTRUCTIONS_2")),
			stringPtr(new string("left-right-up-down to rotate the camera")));
	GameInformations::getInstance().getOrCreateGameInformation(
			stringPtr(new string("INSTRUCTIONS_3")),
			stringPtr(new string("B to toggle wireframe rendering")));
}

int main(void) {

	LOG4CXX_INFO(logger, "Controls :");
	LOG4CXX_INFO(logger, "Esc to exit / Space to toggle rotation / left-right-up-down to rotate the camera");
	LOG4CXX_INFO(logger, "Entering application.");

	generateDisplayInformations();
	ScenePtr scene = ScenePtr(new SimpleCameraScene());
	scene->registerCameraControlHandlers();

	stringPtr windowTitle;
	computeWindowTitle(windowTitle);
	WindowPropertiesPtr windowProperties = WindowPropertiesPtr(new WindowProperties(320, 240, windowTitle));
	LauncherPtr launcher = LauncherPtr(new GLFWLauncher(scene, windowProperties));

	try {
		launcher->setFontPath(initial3d::stringPtr(new std::string("Timeless.ttf")));

		return launcher->run();
	} catch(Initial3dException &e) {
		LOG4CXX_FATAL(logger, std::string(e.getMessage()));
		return -1;
	}
}




