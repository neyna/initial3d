#ifndef INITIAL3DEXCEPTION_HPP_
#define INITIAL3DEXCEPTION_HPP_

#include "../all_includes.hpp"

namespace initial3d {
namespace exception {

class Initial3dException {
public:
	Initial3dException(const char *message);
	virtual ~Initial3dException();
	const char* getMessage();
private:
	const char *message;
};

} /* namespace exception */
} /* namespace initial3d */
#endif /* INITIAL3DEXCEPTION_HPP_ */
