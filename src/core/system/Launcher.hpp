#ifndef LAUNCHER_HPP_
#define LAUNCHER_HPP_

#include "../initial3d_basics.hpp"
#include "../scene/Scene.hpp"
#include "../system/WindowProperties.hpp"
#include "FontRenderer.hpp"
#include "FTGLPixmapFontFontRenderer.hpp"

using namespace initial3d::scene;

namespace initial3d {
namespace system {

class WindowProperties;
typedef std::shared_ptr<WindowProperties> WindowPropertiesPtr;

/**
 * Notes for implementers :
 * - you must call widowResized on the fontRenderPtr when the window is resized
 */
class Launcher {
public:
	static log4cxx::LoggerPtr logger;
	Launcher(ScenePtr &scene);
	Launcher(ScenePtr &scene, WindowPropertiesPtr &windowProperties);
	virtual ~Launcher();
	virtual int run();

	void setFontPath(stringPtr fontPath);
protected:
	ScenePtr scene;
	WindowPropertiesPtr windowPropertiesPtr;
	FontRendererPtr fontRenderPtr;
	stringPtr fontPath = nullptr;
	/**
	 * Implementations must call this method after OpenGL context is set
	 */
	void afterOpenGLInit();
};

typedef std::shared_ptr<Launcher> LauncherPtr;

} /* namespace system */
} /* namespace initial3d */

#endif /* LAUNCHER_HPP_ */
