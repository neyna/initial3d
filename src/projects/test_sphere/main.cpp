#include <initial3d.hpp>

using namespace initial3d::exception;
using namespace initial3d::scene;
using namespace initial3d::system;
using std::string;
using initial3d::stringPtr;
using initial3d::objects::ThreeDimensionsObject;
using initial3d::objects::ThreeDimensionObjectPtr;
using initial3d::objects::Sphere;
using initial3d::utils::GameInformations;

using initial3d::control::ControlHandlerPtr;
using initial3d::control::SphericalCameraControlHandler;
using initial3d::scene::SphericalCamera;

using namespace log4cxx;

LoggerPtr logger(Logger::getLogger("initial3d.projects.testsphere.main"));

int main(void) {

	LOG4CXX_INFO(logger, "Entering application.");

	GameInformations::getInstance().getOrCreateGameInformation(stringPtr(new string("PROGRAM_NAME")), stringPtr(new string("Test Sphere")));

	std::shared_ptr<Camera> camera(new SphericalCamera());
	ScenePtr scene = ScenePtr(new Scene(camera));
	// add controls
	ControlHandlerPtr controlHandlerPtr(new SphericalCameraControlHandler((SphericalCamera*)camera.get()));
	scene->registerControlHandler(controlHandlerPtr);
	// todo (instead of the above code) : scene->registerDefaultCameraControlHandlers();


	WindowPropertiesPtr windowProperties = WindowPropertiesPtr(new WindowProperties(320, 240));
	LauncherPtr launcher = LauncherPtr(new GLFWLauncher(scene, windowProperties));

	ThreeDimensionObjectPtr spherePtr = ThreeDimensionObjectPtr(new Sphere());
	glm::vec3 color(0.3f, 0.5f, 0.3f);
	spherePtr->setColor(color);

	scene->addObject(spherePtr);
	scene->setWireFrameRendering(true);

	try {
		launcher->setFontPath(initial3d::stringPtr(new std::string("Timeless.ttf")));

		return launcher->run();
		return 0;
	} catch(Initial3dException &e) {
		LOG4CXX_FATAL(logger, std::string(e.getMessage()));
		return -1;
	}
}




