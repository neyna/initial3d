#ifndef SHADERLOADER_HPP_
#define SHADERLOADER_HPP_

#include "../initial3d.hpp"

namespace initial3d {
namespace utils {

class ShaderLoader {
public:
	/**
	 * Load vertex/fragment files and compile them
	 * Returns the programId
	 */
	static GLuint loadShaders(const char *vertexFilePath,const char *fragmentFilePath);
private:
	ShaderLoader();
	virtual ~ShaderLoader();
	/**
	 * Return a 2D char array representing all lines of the file (OpenGL requires it)
	 */
	static std::string* readShaderSource(const char* vertexFilePath);
	static void loadAndCompileShader(GLuint vertexShaderId, const char* vertexShaderFilePath);
};

} /* namespace utils */
} /* namespace initial3d */
#endif /* SHADERLOADER_HPP_ */
