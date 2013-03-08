#ifndef SCENE_HPP_
#define SCENE_HPP_

namespace initial3d {

class Scene {
public:
	/**
	 * Do not use any openGL function in this constructor because openGL context won't be initialized yet
	 */
	Scene();
	virtual ~Scene();
	/**
	 * Must be called by Launcher after OpenGL is initialized.
	 */
	virtual void initAfterOpenGLLoaded();
	/**
	 * Compute the next frame for the scene.
	 */
	virtual void computeNextFrame();
	/**
	 * Render the current frame to the screen
	 */
	virtual void draw();
};

} /* namespace initial3d */
#endif /* SCENE_HPP_ */
