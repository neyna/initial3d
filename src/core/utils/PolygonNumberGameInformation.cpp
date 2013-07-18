#include "PolygonNumberGameInformation.hpp"

using boost::format;

namespace initial3d {
namespace utils {

stringPtr PolygonNumberGameInformation::POLYGON_NUMBER = stringPtr(new std::string("POLYGON_NUMBER"));

PolygonNumberGameInformation::PolygonNumberGameInformation() : GameInformation(POLYGON_NUMBER, nullptr) {
}

PolygonNumberGameInformation::~PolygonNumberGameInformation() {
}

stringPtr PolygonNumberGameInformation::computeAndGetDisplayText() {
	std::string formattedString = (format("Polygon number : %d") % polygonNumber).str();
	return stringPtr(new std::string(formattedString));
}

void PolygonNumberGameInformation::addPolygons(long polygonToAdd) {
	polygonNumber += polygonToAdd;
}

void PolygonNumberGameInformation::resetPolygonNumber() {
	polygonNumber = 0;
}

} /* namespace utils */
} /* namespace initial3d */
