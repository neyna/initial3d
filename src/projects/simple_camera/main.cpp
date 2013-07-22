#include <initial3d.hpp>
#include "SimpleCameraScene.hpp"

using namespace initial3d;
using namespace initial3d::exception;
using namespace initial3d::scene;
using namespace initial3d::system;
using namespace initial3d::projects::simplecamera;

using initial3d::utils::GameInformations;
using initial3d::control::ControlHandlerPtr;
using initial3d::control::SphericalCameraControlHandler;
using initial3d::scene::SphericalCamera;

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
			stringPtr(new string("Controls : Esc to exit / Space to pause - A to resume ")));
	GameInformations::getInstance().getOrCreateGameInformation(
			stringPtr(new string("INSTRUCTIONS_2")),
			stringPtr(new string("left-right-up-down to rotate the camera")));
}

int main(void) {

	LOG4CXX_INFO(logger, "Controls :");
	LOG4CXX_INFO(logger, "Esc to exit / Space to pause - A to resume / left-right-up-down to rotate the camera");
	LOG4CXX_INFO(logger, "Entering application.");

	generateDisplayInformations();
	ScenePtr scene = ScenePtr(new SimpleCameraScene());

	// add controls
	ControlHandlerPtr controlHandlerPtr(new SphericalCameraControlHandler((SphericalCamera*)scene->getCamera().get()));
	scene->registerControlHandler(controlHandlerPtr);

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




