#ifndef FPSTIMER_H_
#define FPSTIMER_H_

#include "../standard_includes.hpp"

namespace initial3d {

class FPSTimer {
public:
	FPSTimer();
	virtual ~FPSTimer();
	void newFrame();
	double getFps();
protected:
	double lastTime;
	int numberOfFrame;
};

}

#endif /* FPSTIMER_H_ */
