#include <GL/glfw.h>

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

namespace initial3d {
namespace system {

/**
 * Returns time in seconds since program started with highest precision available
 */
inline double getTime() {
	return glfwGetTime();
}

} /* namespace system */
} /* namespace initial3d */
#endif /* SYSTEM_HPP_ */
