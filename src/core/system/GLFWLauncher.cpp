#include "../initial3d.hpp"

using namespace initial3d::utils;
using namespace initial3d::scene;

namespace initial3d {
namespace system {

void resizeWindowCallback(int, int);

GLFWLauncher::GLFWLauncher(Scene *scene) : Launcher(scene) {
}

GLFWLauncher::~GLFWLauncher() {
}

int GLFWLauncher::run() {

	char* softwareVersion = getVersion();
	glfwSetWindowTitle(softwareVersion);

	// Initialise GLFW
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
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
	if (!glfwOpenWindow(640, 480, 0, 0, 0, 0, 32, 0, GLFW_WINDOW)) {
		fprintf(stderr,
				"Failed to open GLFW window. Cannot open OpenGL 3.3 context. If you have an Intel GPU, they are not 3.3 compatible.");
		glfwTerminate();
		return -1;
	}
	// callback for window (version 3.0) : http://www.glfw.org/docs/3.0/window.html
	// for 2.7
	glfwSetWindowSizeCallback(resizeWindowCallback);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		glfwTerminate();
		return -1;
	}

	scene->initAfterOpenGLLoaded();

	glfwSetWindowTitle("Launcher");

	// Ensure we can capture the escape key being pressed below
	glfwEnable(GLFW_STICKY_KEYS);

	// Dark background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	FPSTimer *fpsTimer = new FPSTimer();
	double lastTime = glfwGetTime();

	do {
		// Draw nothing
		fpsTimer->newFrame();
		scene->draw();

		// updating title
		double newTime = glfwGetTime();
		if(newTime-lastTime>2) {
			double fps = fpsTimer->getFps();
			char* buff = (char*) malloc(100*sizeof(char));
			sprintf(buff, "%s - FPS %f", softwareVersion, fps);
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

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	free(softwareVersion);

	return 0;
}

void GLFWCALL resizeWindowCallback(int width, int height) {
	glViewport(0, 0, width, height);
}

} /* namespace system */
} /* namespace initial3d */
