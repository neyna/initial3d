#ifndef KEYHANDLER_HPP_
#define KEYHANDLER_HPP_

#include "../initial3d_basics.hpp"

namespace initial3d {
namespace control {

/**
 * Class to handle controls, i.e. Keyboard, mouse, etc ..
 */
class ControlHandler {
public:
	ControlHandler();
	virtual ~ControlHandler();
	virtual void keyPressed(KeyCode keyCode) = 0;
	virtual void keyReleased(KeyCode keyCode) = 0;
};

typedef std::shared_ptr<ControlHandler> ControlHandlerPtr;

} /* namespace control */
} /* namespace initial3d */
#endif /* KEYHANDLER_HPP_ */
