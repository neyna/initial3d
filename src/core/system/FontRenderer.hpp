#ifndef FONTRENDERER_HPP_
#define FONTRENDERER_HPP_

#include "../initial3d_basics.hpp"
#include "FontBox.hpp"

namespace initial3d {
namespace system {

/**
 * Render text beginning from top to bottom (aligning it to the left)
 */
class FontRenderer {
public:
	FontRenderer(int screenWidth, int screenHeight);
	virtual ~FontRenderer();

	/**
	 * Reset the renderer, makes him draw from top again
	 */
	void reset();
	/**
	 * Render a line under the last one
	 */
	void renderNewLine(stringPtr text);
	virtual void renderNewLine(stringPtr text, double xPosition, double yPosition) = 0;

	/**
	 * Method called by the Launcher when the window is resized
	 */
	void widowResized(int newScreenWidth, int newScreenHeight);

	/**
	 * Compute the box for the given text
	 */
	virtual FontBoxPtr getFontBox(stringPtr text) = 0;
private:
	int screenWidth = 0;
	int screenHeight = 0;
	double currentHeight = 0;
	double lineOffset = 2;
};

typedef std::shared_ptr<FontRenderer> FontRendererPtr;

} /* namespace system */
} /* namespace initial3d */
#endif /* FONTRENDERER_HPP_ */
