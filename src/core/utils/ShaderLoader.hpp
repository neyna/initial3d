#ifndef SHADERLOADER_HPP_
#define SHADERLOADER_HPP_

#include "../initial3d_basics.hpp"

namespace initial3d {
namespace utils {


class ShaderLoader {
public:
	static log4cxx::LoggerPtr logger;

	/**
	 * Load vertex/fragment files and compile them
	 * Returns the programId
	 */
	static GLuint loadShaders(stringPtr &vertexShaderSource, stringPtr &fragmentShaderSource,
			const std::shared_ptr<std::vector<std::string>> parametersToBind = nullptr);

	static GLuint loadShadersFromFiles(stringPtr &vertexFilePath, stringPtr &fragmentFilePath,
				const std::shared_ptr<std::vector<std::string>> parametersToBind = nullptr);

private:
	ShaderLoader();
	virtual ~ShaderLoader();

	static void loadAndCompileShader(GLuint shaderId, stringPtr &shaderSource);
public:
	static std::string* readShaderSourceFromFile(stringPtr &filePath);
};

} /* namespace utils */
} /* namespace initial3d */
#endif /* SHADERLOADER_HPP_ */
