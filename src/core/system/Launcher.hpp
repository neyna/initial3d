#ifndef LAUNCHER_HPP_
#define LAUNCHER_HPP_

#include "../initial3d.hpp"
using namespace initial3d::scene;

namespace initial3d {
namespace system {

class WindowProperties;
typedef std::shared_ptr<WindowProperties> WindowPropertiesPtr;

class Launcher {
public:
	Launcher(ScenePtr &scene);
	Launcher(ScenePtr &scene, WindowPropertiesPtr &windowProperties);
	virtual ~Launcher();
	virtual int run();
protected:
	ScenePtr scene;
	WindowPropertiesPtr windowPropertiesPtr;
};

typedef std::shared_ptr<Launcher> LauncherPtr;

} /* namespace system */
} /* namespace initial3d */

#endif /* LAUNCHER_HPP_ */
