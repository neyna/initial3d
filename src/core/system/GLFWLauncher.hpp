#ifndef LFWLAUNCHER_
#define LFWLAUNCHER_

#include "../initial3d_basics.hpp"
#include "Launcher.hpp"
#include "../scene/Scene.hpp"
#include "../system/WindowProperties.hpp"
#include <GL/glfw.h>

using namespace initial3d::scene;

namespace initial3d {
namespace system {

class GLFWLauncher : public Launcher {
public:
	static log4cxx::LoggerPtr logger;
	GLFWLauncher(ScenePtr &scene);
	GLFWLauncher(ScenePtr &scene, WindowPropertiesPtr &windowProperties);
	virtual ~GLFWLauncher();
	virtual int run() override;
protected:
};

} /* namespace system */
} /* namespace initial3d */

#endif /* LFWLAUNCHER_ */
