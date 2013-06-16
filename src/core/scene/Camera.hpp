#ifndef CAMERA_H_
#define CAMERA_H_

using namespace glm;

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
	/// @param up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
	void lookAt(vec3 &eye, vec3 &center, vec3 &up);
	mat4 getViewProjectionMatrix();
private:
	mat4 projection;
	mat4 view;
};

} /* namespace scene */
} /* namespace initial3d */
#endif /* CAMERA_H_ */
