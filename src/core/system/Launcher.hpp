#ifndef LAUNCHER_HPP_
#define LAUNCHER_HPP_

#include "../initial3d.hpp"
using namespace initial3d::scene;

namespace initial3d {
namespace system {

class WindowProperties;

class Launcher {
public:
	Launcher(Scene *scene);
	Launcher(Scene *scene, WindowProperties *windowProperties);
	virtual ~Launcher();
	virtual int run();
protected:
	Scene *scene = NULL;
	WindowProperties *windowProperties = NULL;
};

} /* namespace system */
} /* namespace initial3d */

#endif /* LAUNCHER_HPP_ */
