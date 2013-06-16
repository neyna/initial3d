#include "WindowProperties.hpp"

namespace initial3d {
namespace system {

WindowProperties::WindowProperties() : width(640), height(480), windowTitle(new std::string("Launcher")) {
}

WindowProperties::WindowProperties(int width, int height) : width(width), height(height), windowTitle(new std::string("Launcher")) {
}

WindowProperties::WindowProperties(int width, int height, string* windowTitle) : width(width), height(height), windowTitle(windowTitle) {
}

WindowProperties::~WindowProperties() {
}

int WindowProperties::getHeight() const {
	return height;
}

int WindowProperties::getWidth() const {
	return width;
}

const string* WindowProperties::getWindowTitle() const {
	return windowTitle;
}

} /* namespace system */
} /* namespace initial3d */
