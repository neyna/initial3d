#include "GameInformation.hpp"

namespace initial3d {
namespace utils {

GameInformation::GameInformation(stringPtr name, stringPtr displayText) : name(name), displayText(displayText) {
}

GameInformation::~GameInformation() {
}

void GameInformation::updateDisplayText(stringPtr displayText) {
	this->displayText = displayText;
}

stringPtr GameInformation::computeAndGetDisplayText() {
	return displayText;
}

} /* namespace utils */
} /* namespace initial3d */
