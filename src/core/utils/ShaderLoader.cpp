#include "../initial3d.hpp"

#include <fstream>

using namespace initial3d::exception;
using namespace std;
using namespace log4cxx;
using boost::format;

namespace initial3d {
namespace utils {

LoggerPtr ShaderLoader::logger = LoggerPtr(Logger::getLogger("initial3d.utils.ShaderLoader"));

ShaderLoader::ShaderLoader() {
}

ShaderLoader::~ShaderLoader() {
}

string* ShaderLoader::readShaderSourceFromFile(stringPtr &filePath) {

	LOG4CXX_DEBUG(logger, format("Reading file : %s") % filePath->c_str());

	std::string *result = new string("");
	std::ifstream fileIfStream(filePath->c_str(), std::ios::in);
	if (fileIfStream.is_open()) {
		std::string line = "";
		while (getline(fileIfStream, line)) {
			*result += '\n' + line;
		}
		fileIfStream.close();
	} else {
		LOG4CXX_ERROR(logger, format("Impossible to open file %s") % filePath->c_str());
		throw Initial3dException((format("Impossible to open file %s") % filePath->c_str()).str().c_str());
	}

	return result;
}

void ShaderLoader::loadAndCompileShader(GLuint shaderId, stringPtr &shaderSource) {

	// Compile Vertex Shader
	GLint result = GL_FALSE;
	int infoLogLength;
	LOG4CXX_DEBUG(logger, format("Compiling shader : \n%s") % shaderSource->c_str());
	const char* cStr = shaderSource->c_str();
	glShaderSource(shaderId, 1, &cStr, NULL);

	glCompileShader(shaderId);
	// Check Vertex Shader
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
	if ( result != GL_TRUE ) {
		std::vector<char> shaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(shaderId, infoLogLength, NULL,
				&shaderErrorMessage[0]);
		LOG4CXX_ERROR(logger, format("Shader compilation problem : %s") % &shaderErrorMessage[0]);
		throw Initial3dException((format("Shader compilation problem : %s") % &shaderErrorMessage[0]).str().c_str());
	}
}

GLuint ShaderLoader::loadShadersFromFiles(stringPtr &vertexShaderFilePath,
		stringPtr &fragmentShaderFilePath, const std::shared_ptr<std::vector<std::string>> parametersToBind) {
	LOG4CXX_DEBUG(logger,
			format("Loading vertex shader %s and fragment shader %s") % vertexShaderFilePath->c_str() % fragmentShaderFilePath->c_str());

	// load file
	stringPtr vertexShaderSource = stringPtr(readShaderSourceFromFile(vertexShaderFilePath));
	stringPtr fragmentShaderSource = stringPtr(readShaderSourceFromFile(fragmentShaderFilePath));

	return loadShaders(vertexShaderSource, fragmentShaderSource, parametersToBind);
}

GLuint ShaderLoader::loadShaders(stringPtr &vertexShaderSource, stringPtr &fragmentShaderSource,
		const std::shared_ptr<std::vector<std::string> > parametersToBind) {
	// Create the shaders
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	// Compile shaders
	ShaderLoader::loadAndCompileShader(vertexShaderId, vertexShaderSource);
	ShaderLoader::loadAndCompileShader(fragmentShaderId, fragmentShaderSource);

	// Link the program
	LOG4CXX_DEBUG(logger, "Linking program");

	GLint result = GL_FALSE;
	int infoLogLength;

	GLuint programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);

	int attribLocationIndex = 0;
	if (parametersToBind != nullptr) {
		for (string parameterToBind : *parametersToBind.get()) {
			glBindAttribLocation(programId, attribLocationIndex++, parameterToBind.c_str());
		}
	}


	glLinkProgram(programId);

	// Check the program
	glGetProgramiv(programId, GL_LINK_STATUS, &result);
	glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
	if ( result != GL_TRUE ) {
		std::vector<char> ProgramErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(programId, infoLogLength, NULL, &ProgramErrorMessage[0]);
		LOG4CXX_ERROR(logger, format("Shader compilation problem : %s") % &ProgramErrorMessage[0]);
		throw Initial3dException((format("Shader compilation problem : %s") % &ProgramErrorMessage[0]).str().c_str());
	}

	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);

	LOG4CXX_DEBUG(logger, "Loading shader done");
	return programId;
}

} /* namespace utils */
} /* namespace initial3d */
