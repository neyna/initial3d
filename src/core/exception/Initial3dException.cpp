#include "Initial3dException.hpp"

namespace initial3d {
namespace exception {

Initial3dException::Initial3dException(const char *message) {
	this->message = message;
}

Initial3dException::~Initial3dException() {
	delete message;
}

const char* Initial3dException::getMessage() {
	return message;
}

} /* namespace exception */
} /* namespace initial3d */
