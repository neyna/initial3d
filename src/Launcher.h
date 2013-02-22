#ifndef LAUNCHER2_HPP_
#define LAUNCHER2_HPP_

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glfw.h>

#include <version.h>

#include <glm/glm.hpp>
using namespace glm;

class Launcher {
public:
	Launcher();
	virtual ~Launcher();
	int run();
protected:
};

#endif /* LAUNCHER2_HPP_ */
