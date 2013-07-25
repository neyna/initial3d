#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "../initial3d_basics.hpp"
#include "../objects/ThreeDimensionsObject.hpp"
#include "Camera.hpp"
#include "../controls/ControlHandler.hpp"

using initial3d::objects::ThreeDimensionObjectPtr;
using initial3d::control::ControlHandlerPtr;

namespace initial3d {
namespace scene {

class Scene {
public:
	/**
	 * Do not use any openGL function in this constructor because openGL context won't be initialized yet
	 */
	Scene();
	Scene(std::shared_ptr<Camera> camera);
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

	/**
	 * Add object to be managed by the scene
	 */
	void addObject(ThreeDimensionObjectPtr &threeDimensionObjectPtr);

	std::shared_ptr<Camera> getCamera();
	void setCamera(std::shared_ptr<Camera> &camera);

	virtual void keyPressed(KeyCode keyCode);
	virtual void keyReleased(KeyCode keyCode);

	void setWireFrameRendering(bool status);
	void toggleWireFrameRendering();

	void registerControlHandler(ControlHandlerPtr controlHandlerPtr);
	/**
	 * Register all camera's ControlHandler to this scene
	 */
	void registerCameraControlHandlers();

protected:
	std::shared_ptr<Camera> camera;
	std::vector<ThreeDimensionObjectPtr> threeDimensionsObjects;
	std::vector<ControlHandlerPtr> controlHandlers;
	bool wireframeRendering;

private:
	/**
	 * Method called before each scene rendering (i.e. each frame)
	 * Clean the screen, set background color, set culling mode, etc ...
	 */
	void initRendering();
};

typedef std::shared_ptr<Scene> ScenePtr;

}
} /* namespace initial3d */
#endif /* SCENE_HPP_ */
