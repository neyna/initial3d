#ifndef FONTBOX_HPP_
#define FONTBOX_HPP_

#include "FontPoint.hpp"

namespace initial3d {
namespace system {

class FontBox {
public:
	FontBox(FontPointPtr upper, FontPointPtr lower);
	virtual ~FontBox();
	/**
	 * Upper right point
	 */
	FontPointPtr upper;
	/**
	 * Lower left point
	 */
	FontPointPtr lower;
};

typedef std::shared_ptr<FontBox> FontBoxPtr;

} /* namespace system */
} /* namespace initial3d */
#endif /* FONTBOX_HPP_ */
