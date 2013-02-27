#include "FPSTimer.h"

namespace initial3d {

FPSTimer::FPSTimer() {
	lastTime = glfwGetTime();
	numberOfFrame = 0;
}

FPSTimer::~FPSTimer() {
}

void FPSTimer::newFrame() {
	numberOfFrame++;
}

double FPSTimer::getFps() {
	double newTime = glfwGetTime();
	double timeDifference = newTime - lastTime;
	double fps = numberOfFrame / timeDifference;
	lastTime = newTime;
	numberOfFrame = 0;
	return fps;
}

}

