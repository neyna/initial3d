#ifndef LAUNCHER2_HPP_
#define LAUNCHER2_HPP_

#include "standard_includes.hpp"
#include <version.hpp>
#include "objects/FirstTriangle.hpp"
#include "utils/FPSTimer.hpp"

class Launcher {
public:
	Launcher();
	virtual ~Launcher();
	int run();
protected:
};

#endif /* LAUNCHER2_HPP_ */
