#ifndef GAMEINFORMATIONS_HPP_
#define GAMEINFORMATIONS_HPP_

#include "../initial3d_basics.hpp"
#include "../system/FontRenderer.hpp"
#include "GameInformation.hpp"

using initial3d::system::FontRendererPtr;

namespace initial3d {
namespace utils {

class GameInformations {
public:
	static GameInformations& getInstance() {
		static GameInformations instance; 	// Guaranteed to be destroyed.
        									// Instantiated on first use.
		return instance;
	}
	void render(FontRendererPtr &fontRenderer);
	void addGameInformation(GameInformationPtr gameInformationPtr);
	GameInformationPtr getOrCreateGameInformation(stringPtr name, stringPtr text = stringPtr(new std::string("")));
private:
	GameInformations();
    // We need to declare the following two methods to make sure they
    // are unaccessable otherwise we may accidently get copies of
    // your singleton appearing.
	GameInformations(GameInformations const&);
    void operator=(GameInformations const&);

    std::vector<GameInformationPtr> gameInformations = std::vector<GameInformationPtr>(0);
};

} /* namespace utils */
} /* namespace initial3d */
#endif /* GAMEINFORMATIONS_HPP_ */
