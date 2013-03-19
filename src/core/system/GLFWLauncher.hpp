#ifndef LFWLAUNCHER_
#define LFWLAUNCHER_

#include "../initial3d.hpp"
#include <GL/glfw.h>

using namespace initial3d::scene;

namespace initial3d {
namespace system {

class GLFWLauncher : public Launcher {
public:
	GLFWLauncher(Scene *scene);
	virtual ~GLFWLauncher();
	virtual int run();
protected:
};

} /* namespace system */
} /* namespace initial3d */

#endif /* LFWLAUNCHER_ */
