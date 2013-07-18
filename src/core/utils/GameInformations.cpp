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
		fontRenderer->renderNewLine(gameInformationPtr->computeAndGetDisplayText());
	}
}

void GameInformations::addGameInformation(GameInformationPtr gameInformationPtr) {
	gameInformations.push_back(gameInformationPtr);
}

GameInformationPtr GameInformations::getOrCreateGameInformation(stringPtr name, stringPtr text) {
	for (GameInformationPtr gameInformationPtr : gameInformations) {
		if( (*gameInformationPtr->getName().get()) == (*name.get()) ) {
			return gameInformationPtr;
		}
	}
	GameInformationPtr result(new GameInformation(name, text));
	gameInformations.push_back(result);
	return result;
}

GameInformations::GameInformations() {
}


} /* namespace utils */
} /* namespace initial3d */

