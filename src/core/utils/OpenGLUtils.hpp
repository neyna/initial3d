#ifndef OPENGLUTILS_HPP_
#define OPENGLUTILS_HPP_

namespace initial3d {
namespace utils {

inline void printOpenGLErrors() {
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error: " << err << std::endl;
	}
}


} /* namespace utils */
} /* namespace initial3d */
#endif /* OPENGLUTILS_HPP_ */
