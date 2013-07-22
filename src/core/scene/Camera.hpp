#ifndef CAMERA_H_
#define CAMERA_H_

#include "../initial3d_basics.hpp"
#include "../controls/ControlHandler.hpp"

using initial3d::control::ControlHandlerPtr;

namespace initial3d {
namespace scene {

class Camera {
public:
	Camera();
	Camera(float & fovy, float & aspect, float & near, float & far);
	virtual ~Camera();
	/// Set the view direction
	///
	/// @param eye Position of the camera
	/// @param center Position where the camera is looking at
	/// @param up vector (does not need to be normalized), how the camera is oriented). Typically (0, 0, 1)
	void lookAt(glm::vec3 &eye, glm::vec3 &center, glm::vec3 &up);
	std::shared_ptr<glm::mat4> getViewProjectionMatrix();
	/**
	 * This function is called every frame.
	 * Implementations should update position, lookAt, etc ...
	 */
	virtual void update();
	std::vector<ControlHandlerPtr> &getControlHandlers();
protected:
	glm::mat4 projection;
	glm::mat4 view;
	std::vector<ControlHandlerPtr> controlHandlers = std::vector<ControlHandlerPtr>(0);
};

} /* namespace scene */
} /* namespace initial3d */
#endif /* CAMERA_H_ */
