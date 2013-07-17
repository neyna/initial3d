#include "Launcher.hpp"
#include "../exception/Initial3dException.hpp"
#include <fstream>

using log4cxx::LoggerPtr;
using log4cxx::Logger;
using initial3d::exception::Initial3dException;
using boost::format;

namespace initial3d {
namespace system {

LoggerPtr Launcher::logger = LoggerPtr(Logger::getLogger("initial3d.system.Launcher"));

Launcher::Launcher(ScenePtr &scene) {
	this->scene = scene;
	this->windowPropertiesPtr = WindowPropertiesPtr(new WindowProperties());
}

Launcher::~Launcher() {
}

Launcher::Launcher(ScenePtr &scene, WindowPropertiesPtr &windowProperties) {
	this->scene = scene;
	this->windowPropertiesPtr = windowProperties;
}

int Launcher::run() {
	throw "Should never get here because this is an abstract class.";
}

void Launcher::setFontPath(stringPtr fontPath) {
	// check if file exists
	std::ifstream ttfFile(fontPath->c_str(), std::ios::binary);
	if ( ! ttfFile) {
		LOG4CXX_ERROR(logger, format("Font file does not exists '%s'") % fontPath->c_str());
		throw Initial3dException( (format("Font file does not exists '%s'")  % fontPath->c_str()).str().c_str() );
	}
	this->fontPath = fontPath;
}

void Launcher::afterOpenGLInit() {
	if(fontPath != nullptr) {
		fontRenderPtr = FontRendererPtr(new FTGLPixmapFontFontRenderer(fontPath,
				windowPropertiesPtr->getWidth(), windowPropertiesPtr->getHeight()));
	}
}

} /* namespace system */
} /* namespace initial3d */
