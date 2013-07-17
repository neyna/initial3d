#ifndef FONTPOINT_HPP_
#define FONTPOINT_HPP_

#include "../initial3d_basics.hpp"

namespace initial3d {
namespace system {

class FontPoint {
public:
	FontPoint();
	FontPoint(double x, double y);
	virtual ~FontPoint();
	double x = 0;
	double y = 0;
};

typedef std::shared_ptr<FontPoint> FontPointPtr;

} /* namespace system */
} /* namespace initial3d */
#endif /* FONTPOINT_HPP_ */
