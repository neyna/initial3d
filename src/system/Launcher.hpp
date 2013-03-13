#ifndef LAUNCHER2_HPP_
#define LAUNCHER2_HPP_

#include "../all_includes.hpp"
using namespace initial3d::scene;

namespace initial3d {
namespace system {

class Launcher {
public:
	Launcher(Scene *scene);
	virtual ~Launcher();
	virtual int run();
protected:
	Scene *scene;
};

} /* namespace system */
} /* namespace initial3d */

#endif /* LAUNCHER2_HPP_ */
