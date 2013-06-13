#include "../initial3d.hpp"

#include <fstream>

using namespace initial3d::exception;
using namespace std;
using boost::format;

namespace initial3d {
namespace utils {

LoggerPtr shaderLoaderlogger(Logger::getLogger("initial3d.utils.ShaderLoader"));

ShaderLoader::ShaderLoader() {
}

ShaderLoader::~ShaderLoader() {
}

string* ShaderLoader::readShaderSource(const char* fileName) {

	LOG4CXX_DEBUG(shaderLoaderlogger, format("Reading file : %s") % fileName);

	std::string *result = new string("");
	std::ifstream fileIfStream(fileName, std::ios::in);
	if (fileIfStream.is_open()) {
		std::string line = "";
		while (getline(fileIfStream, line)) {
			*result += '\n' + line;
		}
		fileIfStream.close();
	} else {
		LOG4CXX_ERROR(shaderLoaderlogger, format("Impossible to open file %s") % fileName);
		throw Initial3dException((format("Impossible to open file %s") % fileName).str().c_str());
	}

	return result;
}

void ShaderLoader::loadAndCompileShader(GLuint shaderId,
		const char* shaderFilePath) {
	// load file
	string* shaderSource = readShaderSource(shaderFilePath);
	// Compile Vertex Shader
	GLint result = GL_FALSE;
	int infoLogLength;
	LOG4CXX_DEBUG(shaderLoaderlogger, format("Compiling shader : %s") % shaderFilePath);
	const char* cStr = shaderSource->c_str();
	glShaderSource(shaderId, 1, &cStr, NULL);
	delete shaderSource;

	glCompileShader(shaderId);
	// Check Vertex Shader
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
	if ( result != GL_TRUE ) {
		std::vector<char> shaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(shaderId, infoLogLength, NULL,
				&shaderErrorMessage[0]);
		LOG4CXX_ERROR(shaderLoaderlogger, format("Shader compilation problem : %s") % &shaderErrorMessage[0]);
		throw Initial3dException((format("Shader compilation problem : %s") % &shaderErrorMessage[0]).str().c_str());
	}
}

GLuint ShaderLoader::loadShaders(const char* vertexShaderFilePath,
		const char* fragmentShaderFilePath) {
	LOG4CXX_DEBUG(shaderLoaderlogger,
			format("Loading vertex shader %s and fragment shader %s") % vertexShaderFilePath % fragmentShaderFilePath);

	// Create the shaders
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Compile shaders
	ShaderLoader::loadAndCompileShader(vertexShaderId, vertexShaderFilePath);
	ShaderLoader::loadAndCompileShader(fragmentShaderID, fragmentShaderFilePath);

	// Link the program
	LOG4CXX_DEBUG(shaderLoaderlogger, "Linking program");

	GLint result = GL_FALSE;
	int infoLogLength;

	GLuint programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderID);

	//glBindAttribLocation(vertexShaderId, 0, "vertexPosition_modelspace");

	glLinkProgram(programId);

	// Check the program
	glGetProgramiv(programId, GL_LINK_STATUS, &result);
	glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
	if ( result != GL_TRUE ) {
		std::vector<char> ProgramErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(programId, infoLogLength, NULL, &ProgramErrorMessage[0]);
		LOG4CXX_ERROR(shaderLoaderlogger, format("Shader compilation problem : %s") % &ProgramErrorMessage[0]);
		throw Initial3dException((format("Shader compilation problem : %s") % &ProgramErrorMessage[0]).str().c_str());
	}

	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderID);

	LOG4CXX_DEBUG(shaderLoaderlogger, "Loading shader done");
	return programId;

}

} /* namespace utils */
} /* namespace initial3d */
