#include "FTGLPixmapFontFontRenderer.hpp"
#include "../exception/Initial3dException.hpp"

using initial3d::exception::Initial3dException;
using boost::format;
using log4cxx::LoggerPtr;
using log4cxx::Logger;

namespace initial3d {
namespace system {

LoggerPtr FTGLPixmapFontFontRenderer::logger = LoggerPtr(Logger::getLogger("initial3d.system.FTGLPixmapFontFontRenderer"));

FTGLPixmapFontFontRenderer::FTGLPixmapFontFontRenderer(stringPtr fontPath, int screenWidth, int screenHeight):
		FontRenderer(screenWidth, screenHeight) {
	fontPtr = std::shared_ptr<FTGLPixmapFont>(new FTGLPixmapFont(fontPath->c_str()));
}

FTGLPixmapFontFontRenderer::~FTGLPixmapFontFontRenderer() {
}

void FTGLPixmapFontFontRenderer::renderNewLine(stringPtr text, int xPosition, int yPosition) {
	if(fontPtr == nullptr) {
		LOG4CXX_ERROR(logger, format("Tried to render text '%s' while font is null") % text->c_str());
		throw Initial3dException( (format("Tried to render text '%s' while font is null")  % text->c_str()).str().c_str() );
	}

	fontPtr->FaceSize(25);
	fontPtr->Render(text->c_str());
}

} /* namespace system */
} /* namespace initial3d */
