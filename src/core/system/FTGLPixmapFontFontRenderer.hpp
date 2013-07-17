#ifndef FTGLPIXMAPFONTRENDERER_HPP_
#define FTGLPIXMAPFONTRENDERER_HPP_

#include "../initial3d_basics.hpp"
#include "FontRenderer.hpp"

namespace initial3d {
namespace system {

class FTGLPixmapFontFontRenderer : public FontRenderer {
public:
	static log4cxx::LoggerPtr logger;
	FTGLPixmapFontFontRenderer(stringPtr fontPath, int screenWidth, int screenHeight);
	virtual ~FTGLPixmapFontFontRenderer();
	void renderNewLine(stringPtr text, double xPosition, double yPosition);
	virtual FontBoxPtr getFontBox(stringPtr text);
private:
	std::shared_ptr<FTGLPixmapFont> fontPtr = nullptr;
};

} /* namespace system */
} /* namespace initial3d */
#endif /* FTGLPIXMAPFONTRENDERER_HPP_ */
