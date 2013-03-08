#ifndef LFWLAUNCHER_
#define LFWLAUNCHER_

#include "../all_includes.hpp"
#include <GL/glfw.h>

namespace initial3d {

class GLFWLauncher : public Launcher {
public:
	GLFWLauncher(Scene *scene);
	virtual ~GLFWLauncher();
	virtual int run();
protected:
};

} /* namespace initial3d */

#endif /* LFWLAUNCHER_ */
