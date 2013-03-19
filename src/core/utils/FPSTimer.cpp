#include "../initial3d.hpp"

namespace initial3d {
namespace utils {

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
}

