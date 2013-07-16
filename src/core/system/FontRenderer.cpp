#include "FontRenderer.hpp"

namespace initial3d {
namespace system {

FontRenderer::FontRenderer(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight) {
}

FontRenderer::~FontRenderer() {
}

void FontRenderer::renderNewLine(stringPtr text) {
	this->renderNewLine(text, 0, 0);
}

void FontRenderer::widowResized(int newScreenWidth, int newScreenHeight) {
	this->screenWidth = newScreenWidth;
	this->screenHeight = newScreenHeight;
}

} /* namespace system */
} /* namespace initial3d */
