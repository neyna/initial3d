#ifndef FPSTIMER_H_
#define FPSTIMER_H_

#include "../initial3d_basics.hpp"

namespace initial3d {
namespace utils {

class FPSTimer {
public:
	FPSTimer();
	virtual ~FPSTimer();
	void newFrame();
	double getAndResetFps();
protected:
	double lastTime;
	int numberOfFrame;
};

}
}

#endif /* FPSTIMER_H_ */
