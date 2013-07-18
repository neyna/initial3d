#include "Launcher.hpp"
#include "../exception/Initial3dException.hpp"
#include "../utils/PolygonNumberGameInformation.hpp"
#include "../utils/GameInformations.hpp"
#include <fstream>

using log4cxx::LoggerPtr;
using log4cxx::Logger;
using initial3d::exception::Initial3dException;
using boost::format;

using initial3d::utils::GameInformations;
using initial3d::utils::GameInformationPtr;
using initial3d::utils::PolygonNumberGameInformation;

namespace initial3d {
namespace system {

LoggerPtr Launcher::logger = LoggerPtr(Logger::getLogger("initial3d.system.Launcher"));


Launcher::~Launcher() {
}

Launcher::Launcher(ScenePtr scene, WindowPropertiesPtr windowProperties) {
	this->scene = scene;
	this->windowPropertiesPtr = windowProperties;

	GameInformationPtr PolygonNumberGameInformationPtr = GameInformationPtr(new PolygonNumberGameInformation());
	GameInformations::getInstance().addGameInformation(PolygonNumberGameInformationPtr);
}

Launcher::Launcher(ScenePtr scene) : Launcher(scene, WindowPropertiesPtr(new WindowProperties())) {
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
