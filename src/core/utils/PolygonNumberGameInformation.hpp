#ifndef POLYGONNUMBERGAMEINFORMATION_HPP_
#define POLYGONNUMBERGAMEINFORMATION_HPP_

#include "../initial3d_basics.hpp"
#include "GameInformation.hpp"


namespace initial3d {
namespace utils {

class PolygonNumberGameInformation : public GameInformation {
public:
	static stringPtr POLYGON_NUMBER;
	PolygonNumberGameInformation();
	virtual ~PolygonNumberGameInformation();
	virtual stringPtr computeAndGetDisplayText();
	void addPolygons(long polygonToAdd);
	void resetPolygonNumber();
protected:
	long polygonNumber = 0;
};

} /* namespace utils */
} /* namespace initial3d */
#endif /* POLYGONNUMBERGAMEINFORMATION_HPP_ */
