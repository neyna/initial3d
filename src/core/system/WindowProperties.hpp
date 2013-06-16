#ifndef WINDOWPROPERTIES_H_
#define WINDOWPROPERTIES_H_

#include "../initial3d.hpp"

using namespace std;

namespace initial3d {
namespace system {

class WindowProperties {
public:
	WindowProperties();
	WindowProperties(int width, int height);
	WindowProperties(int width, int height, string *windowTitle);
	virtual ~WindowProperties();
	int getHeight() const;
	int getWidth() const;
	const string* getWindowTitle() const;

protected:
	int width;
	int height;
	string *windowTitle;
};

} /* namespace system */
} /* namespace initial3d */
#endif /* WINDOWPROPERTIES_H_ */
