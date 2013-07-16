#ifndef GAMEINFORMATION_HPP_
#define GAMEINFORMATION_HPP_

#include "../initial3d_basics.hpp"

namespace initial3d {
namespace utils {

class GameInformation {
public:
	GameInformation(stringPtr name, stringPtr displayText);
	virtual ~GameInformation();
	void updateDisplayText(stringPtr displayText);

	const stringPtr& getDisplayText() const {
		return displayText;
	}

private:
	stringPtr name = nullptr;
	stringPtr displayText = nullptr;
};

typedef std::shared_ptr<GameInformation> GameInformationPtr;

} /* namespace utils */
} /* namespace initial3d */
#endif /* GAMEINFORMATION_HPP_ */
