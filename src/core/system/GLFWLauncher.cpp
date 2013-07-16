#include "GLFWLauncher.hpp"
#include "../exception/Initial3dException.hpp"
#include "../utils/FPSTimer.hpp"
#include "../system/System.hpp"
#include "../utils/GameInformations.hpp"
#include "FontRenderer.hpp"

using namespace std;

using namespace initial3d::utils;
using namespace initial3d::scene;

using log4cxx::LoggerPtr;
using log4cxx::Logger;
using initial3d::exception::Initial3dException;
using initial3d::system::FontRendererPtr;
using boost::format;

namespace initial3d {
namespace system {

LoggerPtr GLFWLauncher::logger = LoggerPtr(Logger::getLogger("initial3d.system.GLFWLauncher"));

// GLFW callbacks, those are called in the same thread than our object creation
void resizeWindowCallback(int, int);
void keyboardCallback(int, int);
void mouseButtonCallback(int buttonIdentifier, int buttonState);
void mouseWheelCallback(int scroll);
void mousePositionCallback(int x, int y);

// keycodes
const int keyCodeSize = 5;
const array<int, keyCodeSize> glfwKeyCodes = {{GLFW_KEY_ESC, GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT}};
const array<KeyCode, keyCodeSize> enumKeyCodes = {{KEY_ESC, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT}};
const array<KeyCode, 255> latin1KeyCode = {{KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, KEY_11, KEY_12, KEY_13, KEY_14, KEY_15, KEY_16, KEY_17, KEY_18, KEY_19, KEY_20, KEY_21, KEY_22, KEY_23, KEY_24, KEY_25, KEY_26, KEY_27, KEY_28, KEY_29, KEY_30, KEY_31, KEY_32, KEY_33, KEY_34, KEY_35, KEY_36, KEY_37, KEY_38, KEY_39, KEY_40, KEY_41, KEY_42, KEY_43, KEY_44, KEY_45, KEY_46, KEY_47, KEY_48, KEY_49, KEY_50, KEY_51, KEY_52, KEY_53, KEY_54, KEY_55, KEY_56, KEY_57, KEY_58, KEY_59, KEY_60, KEY_61, KEY_62, KEY_63, KEY_64, KEY_65, KEY_66, KEY_67, KEY_68, KEY_69, KEY_70, KEY_71, KEY_72, KEY_73, KEY_74, KEY_75, KEY_76, KEY_77, KEY_78, KEY_79, KEY_80, KEY_81, KEY_82, KEY_83, KEY_84, KEY_85, KEY_86, KEY_87, KEY_88, KEY_89, KEY_90, KEY_91, KEY_92, KEY_93, KEY_94, KEY_95, KEY_96, KEY_97, KEY_98, KEY_99, KEY_100, KEY_101, KEY_102, KEY_103, KEY_104, KEY_105, KEY_106, KEY_107, KEY_108, KEY_109, KEY_110, KEY_111, KEY_112, KEY_113, KEY_114, KEY_115, KEY_116, KEY_117, KEY_118, KEY_119, KEY_120, KEY_121, KEY_122, KEY_123, KEY_124, KEY_125, KEY_126, KEY_127, KEY_128, KEY_129, KEY_130, KEY_131, KEY_132, KEY_133, KEY_134, KEY_135, KEY_136, KEY_137, KEY_138, KEY_139, KEY_140, KEY_141, KEY_142, KEY_143, KEY_144, KEY_145, KEY_146, KEY_147, KEY_148, KEY_149, KEY_150, KEY_151, KEY_152, KEY_153, KEY_154, KEY_155, KEY_156, KEY_157, KEY_158, KEY_159, KEY_160, KEY_161, KEY_162, KEY_163, KEY_164, KEY_165, KEY_166, KEY_167, KEY_168, KEY_169, KEY_170, KEY_171, KEY_172, KEY_173, KEY_174, KEY_175, KEY_176, KEY_177, KEY_178, KEY_179, KEY_180, KEY_181, KEY_182, KEY_183, KEY_184, KEY_185, KEY_186, KEY_187, KEY_188, KEY_189, KEY_190, KEY_191, KEY_192, KEY_193, KEY_194, KEY_195, KEY_196, KEY_197, KEY_198, KEY_199, KEY_200, KEY_201, KEY_202, KEY_203, KEY_204, KEY_205, KEY_206, KEY_207, KEY_208, KEY_209, KEY_210, KEY_211, KEY_212, KEY_213, KEY_214, KEY_215, KEY_216, KEY_217, KEY_218, KEY_219, KEY_220, KEY_221, KEY_222, KEY_223, KEY_224, KEY_225, KEY_226, KEY_227, KEY_228, KEY_229, KEY_230, KEY_231, KEY_232, KEY_233, KEY_234, KEY_235, KEY_236, KEY_237, KEY_238, KEY_239, KEY_240, KEY_241, KEY_242, KEY_243, KEY_244, KEY_245, KEY_246, KEY_247, KEY_248, KEY_249, KEY_250, KEY_251, KEY_252, KEY_253, KEY_254}};


int shouldCloseApplication = 0;
ScenePtr actualScene;
FontRendererPtr fontRendererPtr;

GLFWLauncher::GLFWLauncher(ScenePtr &scene) : Launcher(scene) {
}

GLFWLauncher::~GLFWLauncher() {
}

GLFWLauncher::GLFWLauncher(ScenePtr &scene, WindowPropertiesPtr &windowProperties) : Launcher(scene, windowProperties) {
}

int GLFWLauncher::run() {

	assert(windowPropertiesPtr!=NULL);

	LOG4CXX_INFO(logger, "Initializing GLFW");
	// Initialise GLFW
	if (!glfwInit()) {
		LOG4CXX_ERROR(logger, "Failed to initialize GLFW");
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
	LOG4CXX_DEBUG(logger, "Opening GLFW window");
	if (!glfwOpenWindow(windowPropertiesPtr->getWidth(), windowPropertiesPtr->getHeight(),
			0, 0, 0, 0, 32, 0, GLFW_WINDOW)) {
		LOG4CXX_ERROR(logger, "Failed to open GLFW window. Cannot open OpenGL 3.3 context. If you have an Intel GPU, they are not 3.3 compatible.");
		glfwTerminate();
		return -1;
	}
	// callback for window (version 3.0) : http://www.glfw.org/docs/3.0/window.html
	// for 2.7
	glfwSetWindowSizeCallback(resizeWindowCallback);

	// input callbacks
	glfwSetKeyCallback(keyboardCallback);
	glfwSetMouseWheelCallback(mouseWheelCallback);
	glfwSetMousePosCallback(mousePositionCallback);
	glfwSetMouseButtonCallback(mouseButtonCallback);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		LOG4CXX_ERROR(logger, "Failed to initialize GLEW");
		glfwTerminate();
		return -1;
	}

	this->afterOpenGLInit();
	fontRendererPtr = this->fontRenderPtr;
	scene->initAfterOpenGLLoaded();
	actualScene = scene;

	GameInformationPtr fpsGameInformationPtr(new GameInformation(stringPtr(new string("FPS")), stringPtr(new string("Frame per second :"))));
	GameInformations::getInstance().addGameInformation(fpsGameInformationPtr);

	glfwSetWindowTitle(windowPropertiesPtr->getWindowTitle()->c_str());

	// Ensure we can capture the escape key being pressed below
	glfwEnable(GLFW_STICKY_KEYS);

	FPSTimer *fpsTimer = new FPSTimer();
	double lastTime = getTime();

	LOG4CXX_DEBUG(logger, "Beginning loop");
	do {
		// Draw nothing
		fpsTimer->newFrame();
		scene->draw();

		// updating FPS counter
		double newTime = getTime();
		if(newTime-lastTime>2) {
			double fps = fpsTimer->getAndResetFps();
			char* buff = (char*) malloc(100*sizeof(char));
			sprintf(buff, "Frames per second : %f", fps);
			fpsGameInformationPtr->updateDisplayText(stringPtr(new string(buff)));
			lastTime = newTime;
			free(buff);
		}

		// Render game info to screen
		if(fontRenderPtr != nullptr) {
			GameInformations::getInstance().render(fontRenderPtr);
		}

		// Swap buffers
		glfwSwapBuffers();

	} // Check if the ESC key was pressed or the window was closed
	while ( ! shouldCloseApplication
			&& glfwGetWindowParam(GLFW_OPENED));

	delete fpsTimer;

	LOG4CXX_INFO(logger, "Closing GLFW");
	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

void GLFWCALL resizeWindowCallback(int width, int height) {
	glViewport(0, 0, width, height);
	if(fontRendererPtr != nullptr) {
		fontRendererPtr->widowResized(width, height);
	}
}

KeyCode translateKeyCode(int keyIdentifier) {
	// GLFW_KEY_SPACE is 32, i.e. between 0 and 256, need a little hack tho ..
	if(keyIdentifier == GLFW_KEY_SPACE) {
		return KEY_SPACE;
	}
	if( keyIdentifier > -1 && keyIdentifier < 256) {
		return latin1KeyCode[keyIdentifier];
	}
	for(int i = 0; i < keyCodeSize ; i++) {
		if(glfwKeyCodes[i] == keyIdentifier) {
			return enumKeyCodes[i];
		}
	}
	LOG4CXX_ERROR(GLFWLauncher::logger, format("Unknown key : %d") % keyIdentifier);

	return KEY_UNKNOWN;
}

void GLFWCALL keyboardCallback(int keyIdentifier, int keyState) {
	LOG4CXX_DEBUG(GLFWLauncher::logger, format("Key : %i with state %i") % keyIdentifier % keyState);
	if(keyIdentifier == GLFW_KEY_ESC) {
		shouldCloseApplication = 1;
	}

	KeyCode keyCode = translateKeyCode(keyIdentifier);
	if(keyState == GLFW_PRESS) {
		actualScene->keyPressed(keyCode);
	} else {
		actualScene->keyReleased(keyCode);
	}
}

void GLFWCALL mouseButtonCallback(int buttonIdentifier, int buttonState) {
	LOG4CXX_DEBUG(GLFWLauncher::logger, format("process id :  %d") % getpid());
	int x, y;
	// top left corner
	glfwGetMousePos(&x, &y);
	LOG4CXX_DEBUG(GLFWLauncher::logger, format("Mouse button : %d with state %d at position (%d, %d)") % buttonIdentifier % buttonState % x % y);

}

void GLFWCALL mouseWheelCallback(int scroll) {
	LOG4CXX_DEBUG(GLFWLauncher::logger, format("Mouse wheel (absolute position from start) : %d") % scroll);
}

/**
 * Position relative to the upper left corner
 */
void GLFWCALL mousePositionCallback(int x, int y) {
	LOG4CXX_TRACE(GLFWLauncher::logger, format("Mouse position (x, y) = (%d, %d)") % x % y);
}



} /* namespace system */
} /* namespace initial3d */
