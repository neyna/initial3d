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
	fontPtr = new FTGLPixmapFont(fontPath->c_str());
	if(fontPtr->Error()) {
		LOG4CXX_ERROR(logger, format("Failed to initialize font '%s'") % fontPath->c_str());
		throw Initial3dException( (format("Failed to initialize font '%s'")  % fontPath->c_str()).str().c_str() );
	}
}

FTGLPixmapFontFontRenderer::~FTGLPixmapFontFontRenderer() {
	// TODO find why next line creates a seg fault, seems library issue
	// this will cause a memory leak but it's better than a seg fault
	//delete fontPtr;
}

void FTGLPixmapFontFontRenderer::renderNewLine(stringPtr text, double xPosition, double yPosition) {
	if(fontPtr == nullptr) {
		LOG4CXX_ERROR(logger, format("Tried to render text '%s' while font is null") % text->c_str());
		throw Initial3dException( (format("Tried to render text '%s' while font is null")  % text->c_str()).str().c_str() );
	}

	fontPtr->FaceSize(16);
	FTPoint drawingPoint(xPosition, yPosition);
	fontPtr->Render(text->c_str(), -1, drawingPoint);
}

FontBoxPtr FTGLPixmapFontFontRenderer::getFontBox(stringPtr text) {
	FTBBox ftBBox = fontPtr->BBox(text->c_str());
	//LOG4CXX_TRACE(logger, format("upper : (x %d, y %d) lower (x %d, y %d)") % ftBBox.Upper().X() % ftBBox.Upper().Y() % ftBBox.Lower().X() % ftBBox.Lower().Y());
	FontPointPtr a(new FontPoint(ftBBox.Upper().X(), ftBBox.Upper().Y() ));
	FontPointPtr b(new FontPoint(ftBBox.Lower().X(), ftBBox.Lower().Y() ));
	return FontBoxPtr(new FontBox(
				FontPointPtr(new FontPoint(ftBBox.Upper().X(), ftBBox.Upper().Y() )),
				FontPointPtr(new FontPoint(ftBBox.Lower().X(), ftBBox.Lower().Y() ))
			)
	);
}

} /* namespace system */
} /* namespace initial3d */
