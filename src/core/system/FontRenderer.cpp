#include "FontRenderer.hpp"

using initial3d::system::FontBoxPtr;

namespace initial3d {
namespace system {

FontRenderer::FontRenderer(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight) {
}

FontRenderer::~FontRenderer() {
}

void FontRenderer::renderNewLine(stringPtr text) {
	FontPoint fontPoint;
	FontBoxPtr fontBox = getFontBox(text);
	// we dont care about line width for now
	double height = fontBox->upper->y - fontBox->lower->y;
	currentHeight = currentHeight - height - lineOffset;

	this->renderNewLine(text, 0, currentHeight);
}

void FontRenderer::reset() {
	currentHeight = screenHeight - lineOffset;
}

void FontRenderer::widowResized(int newScreenWidth, int newScreenHeight) {
	this->screenWidth = newScreenWidth;
	this->screenHeight = newScreenHeight;
}

} /* namespace system */
} /* namespace initial3d */
