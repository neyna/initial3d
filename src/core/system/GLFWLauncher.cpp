#include "../initial3d.hpp"

using namespace std;
using namespace log4cxx;
using namespace initial3d::utils;
using namespace initial3d::scene;
using boost::format;

namespace initial3d {
namespace system {

LoggerPtr glfwLauncherlogger(Logger::getLogger("initial3d.system.GLFWLauncher"));

void resizeWindowCallback(int, int);

GLFWLauncher::GLFWLauncher(ScenePtr &scene) : Launcher(scene) {
}

GLFWLauncher::~GLFWLauncher() {
}

GLFWLauncher::GLFWLauncher(ScenePtr &scene, WindowPropertiesPtr &windowProperties) : Launcher(scene, windowProperties) {
}

int GLFWLauncher::run() {

	assert(windowPropertiesPtr!=NULL);

	LOG4CXX_INFO(glfwLauncherlogger, "Initializing GLFW");
	// Initialise GLFW
	if (!glfwInit()) {
		LOG4CXX_ERROR(glfwLauncherlogger, "Failed to initialize GLFW");
		return -1;
	}

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 0);
	// openGL profiles are for openGL > 3.1
	/*
	 * v3.1 removed most of those functions from the API[1]. This also divided the specification into
	 * 2 variations (called profiles): core and compatibility. The compatibility profile retains all
	 * of the functions removed in 3.1, while the core profile does not.
	 */
	//glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	LOG4CXX_DEBUG(glfwLauncherlogger, "Opening GLFW window");
	if (!glfwOpenWindow(windowPropertiesPtr->getWidth(), windowPropertiesPtr->getHeight(),
			0, 0, 0, 0, 32, 0, GLFW_WINDOW)) {
		LOG4CXX_ERROR(glfwLauncherlogger, "Failed to open GLFW window. Cannot open OpenGL 3.3 context. If you have an Intel GPU, they are not 3.3 compatible.");
		glfwTerminate();
		return -1;
	}
	// callback for window (version 3.0) : http://www.glfw.org/docs/3.0/window.html
	// for 2.7
	glfwSetWindowSizeCallback(resizeWindowCallback);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		LOG4CXX_ERROR(glfwLauncherlogger, "Failed to initialize GLEW");
		glfwTerminate();
		return -1;
	}

	scene->initAfterOpenGLLoaded();

	glfwSetWindowTitle(windowPropertiesPtr->getWindowTitle()->c_str());

	// Ensure we can capture the escape key being pressed below
	glfwEnable(GLFW_STICKY_KEYS);

	// Dark background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	FPSTimer *fpsTimer = new FPSTimer();
	double lastTime = getTime();

	LOG4CXX_DEBUG(glfwLauncherlogger, "Beginning loop");
	do {
		// Draw nothing
		fpsTimer->newFrame();
		scene->draw();

		// updating title
		double newTime = getTime();
		if(newTime-lastTime>2) {
			double fps = fpsTimer->getAndResetFps();
			char* buff = (char*) malloc(100*sizeof(char));
			sprintf(buff, "%s - FPS %f", windowPropertiesPtr->getWindowTitle()->c_str(), fps);
			glfwSetWindowTitle(buff);
			lastTime = newTime;
			free(buff);
		}

		// Swap buffers
		glfwSwapBuffers();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS
			&& glfwGetWindowParam(GLFW_OPENED));

	delete fpsTimer;

	LOG4CXX_INFO(glfwLauncherlogger, "Closing GLFW");
	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

void GLFWCALL resizeWindowCallback(int width, int height) {
	glViewport(0, 0, width, height);
}

} /* namespace system */
} /* namespace initial3d */
