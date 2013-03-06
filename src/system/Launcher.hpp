#ifndef LAUNCHER2_HPP_
#define LAUNCHER2_HPP_

#include "../all_includes.hpp"

namespace initial3d {

class Launcher {
public:
	virtual ~Launcher()  {};
	virtual int run(Scene *scene) = 0;
protected:
	Scene *scene;
};

} /* namespace initial3d */

#endif /* LAUNCHER2_HPP_ */
