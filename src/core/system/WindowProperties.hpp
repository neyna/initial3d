#ifndef WINDOWPROPERTIES_H_
#define WINDOWPROPERTIES_H_

#include "../initial3d.hpp"

namespace initial3d {
namespace system {

class WindowProperties {
public:
	WindowProperties();
	WindowProperties(int width, int height);
	WindowProperties(int width, int height, stringPtr windowTitle);
	virtual ~WindowProperties();
	int getHeight() const;
	int getWidth() const;
	const stringPtr getWindowTitle() const;

protected:
	int width;
	int height;
	stringPtr windowTitle;
};

typedef std::shared_ptr<WindowProperties> WindowPropertiesPtr;

} /* namespace system */
} /* namespace initial3d */
#endif /* WINDOWPROPERTIES_H_ */
