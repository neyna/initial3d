#include "Launcher.hpp"
#include "../exception/Initial3dException.hpp"

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
	this->fontPath = fontPath;
}

void Launcher::afterOpenGLInit() {
	if(fontPath != nullptr) {
		fontRenderPtr = FontRendererPtr(new FTGLPixmapFontFontRenderer(stringPtr(new std::string("font.ttf")),
				windowPropertiesPtr->getWidth(), windowPropertiesPtr->getHeight()));
	}
}

} /* namespace system */
} /* namespace initial3d */
