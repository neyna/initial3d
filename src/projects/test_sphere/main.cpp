#include <initial3d.hpp>

using namespace initial3d::exception;
using namespace initial3d::scene;
using namespace initial3d::system;
using initial3d::objects::ThreeDimensionsObject;
using initial3d::objects::ThreeDimensionObjectPtr;
using initial3d::objects::Sphere;

using namespace log4cxx;

LoggerPtr logger(Logger::getLogger("initial3d.projects.testsphere.main"));

int main(void) {

	LOG4CXX_INFO(logger, "Entering application.");
	ScenePtr scene = ScenePtr(new Scene());
	WindowPropertiesPtr windowProperties = WindowPropertiesPtr(new WindowProperties(320, 240));
	LauncherPtr launcher = LauncherPtr(new GLFWLauncher(scene, windowProperties));
	launcher->setFontPath(initial3d::stringPtr(new std::string("font.ttf")));

	ThreeDimensionObjectPtr spherePtr = ThreeDimensionObjectPtr(new Sphere());
	scene->addObject(spherePtr);

	try {
		return launcher->run();
		return 0;
	} catch(Initial3dException &e) {
		LOG4CXX_FATAL(logger, std::string(e.getMessage()));
		return -1;
	}
}




