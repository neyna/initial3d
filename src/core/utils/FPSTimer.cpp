#include "../initial3d.hpp"

using namespace initial3d::system;

namespace initial3d {
namespace utils {

FPSTimer::FPSTimer() {
	lastTime = getTime();
	numberOfFrame = 0;
}

FPSTimer::~FPSTimer() {
}

void FPSTimer::newFrame() {
	numberOfFrame++;
}

double FPSTimer::getAndResetFps() {
	double newTime = getTime();
	double timeDifference = newTime - lastTime;
	double fps = numberOfFrame / timeDifference;
	lastTime = newTime;
	numberOfFrame = 0;
	return fps;
}

}
}

