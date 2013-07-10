#ifndef SHADERSLIBRARY_HPP_
#define SHADERSLIBRARY_HPP_

#include "../initial3d.hpp"

namespace initial3d {
namespace utils {


class ShadersLibrary {
public:
	ShadersLibrary();
	virtual ~ShadersLibrary();
	static std::string DEFAULT_VERTEX_SHADER;
	static std::string DEFAULT_FRAGMENT_SHADER;
};

} /* namespace utils */
} /* namespace initial3d */
#endif /* SHADERSLIBRARY_HPP_ */
