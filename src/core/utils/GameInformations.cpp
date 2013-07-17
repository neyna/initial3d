#include "GameInformations.hpp"
#include "../exception/Initial3dException.hpp"

using initial3d::exception::Initial3dException;

namespace initial3d {
namespace utils {

void GameInformations::render(FontRendererPtr& fontRenderer) {
	if(fontRenderer == nullptr) {
		throw Initial3dException("Tried to render text with a null fontRenderer");
	}

	fontRenderer->reset();
	for (GameInformationPtr gameInformationPtr : gameInformations) {
		fontRenderer->renderNewLine(gameInformationPtr->getDisplayText());
	}
}

void GameInformations::addGameInformation(GameInformationPtr gameInformationPtr) {
	gameInformations.push_back(gameInformationPtr);
}

GameInformations::GameInformations() {
}


} /* namespace utils */
} /* namespace initial3d */

