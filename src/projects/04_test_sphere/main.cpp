#include <initial3d.hpp>
#include "SphereControlHandler.hpp"

using namespace initial3d::exception;
using namespace initial3d::scene;
using namespace initial3d::system;
using std::string;
using initial3d::stringPtr;
using initial3d::objects::ThreeDimensionsObject;
using initial3d::objects::ThreeDimensionObjectPtr;
using initial3d::objects::Sphere;
using initial3d::utils::GameInformations;
using initial3d::scene::SphericalCamera;

using namespace log4cxx;
using namespace initial3d::testsphere;

LoggerPtr logger(Logger::getLogger("initial3d.projects.testsphere.main"));

void generateDisplayInformations();

int main(void) {

	LOG4CXX_INFO(logger, "Entering application.");

	generateDisplayInformations();

	// create scene and camera
	std::shared_ptr<Camera> camera(new SphericalCamera());
	ScenePtr scene = ScenePtr(new Scene(camera));
	// add controls
	scene->registerCameraControlHandlers();
	scene->setWireFrameRendering(true);

	// create launcher
	WindowPropertiesPtr windowProperties = WindowPropertiesPtr(new WindowProperties(320, 240));
	LauncherPtr launcher = LauncherPtr(new GLFWLauncher(scene, windowProperties));

	// create and register sphere object
	ThreeDimensionObjectPtr spherePtr = ThreeDimensionObjectPtr(new Sphere());
	glm::vec3 color(0.3f, 0.5f, 0.3f);
	spherePtr->setColor(color);
	((Sphere*)spherePtr.get())->setRadius(1.5f);

	scene->addObject(spherePtr);
	ControlHandlerPtr sphereControlHandler(new SphereControlHandler((Sphere*)spherePtr.get(), scene));
	scene->registerControlHandler(sphereControlHandler);

	try {
		launcher->setFontPath(initial3d::stringPtr(new std::string("Timeless.ttf")));
		return launcher->run();
		return 0;
	} catch(Initial3dException &e) {
		LOG4CXX_FATAL(logger, std::string(e.getMessage()));
		return -1;
	}
}

void generateDisplayInformations() {
	GameInformations::getInstance().getOrCreateGameInformation(stringPtr(new string("PROGRAM_NAME")), stringPtr(new string("Test Sphere")));
	GameInformations::getInstance().getOrCreateGameInformation(
			stringPtr(new string("INSTRUCTIONS_1")),
			stringPtr(new string("Controls : Esc to exit / Space to toggle rotation")));
	GameInformations::getInstance().getOrCreateGameInformation(
			stringPtr(new string("INSTRUCTIONS_2")),
			stringPtr(new string("left-right-up-down to rotate the camera")));
	GameInformations::getInstance().getOrCreateGameInformation(
			stringPtr(new string("INSTRUCTIONS_3")),
			stringPtr(new string("W to toggle wireframe rendering")));
	GameInformations::getInstance().getOrCreateGameInformation(
			stringPtr(new string("INSTRUCTIONS_4")),
			stringPtr(new string("+/- to increase or decrease Sphere number of subdivision")));
}




