#include "Camera.hpp"

using glm::vec3;
using glm::mat4;

namespace initial3d {
namespace scene {

Camera::Camera() {
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	view = glm::lookAt(	vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
						vec3(0, 0, 0), // and looks at the origin
						vec3(0, 1, 0)  // Head is up
			);
}

Camera::Camera(float & fovy, float & aspect, float & near, float & far) {
	projection = glm::perspective(fovy, aspect, near, far);
}

Camera::~Camera() {

}

void Camera::lookAt(vec3 &eye, vec3 &center, vec3 &up) {
	view = glm::lookAt(	eye, center, up);
}

std::shared_ptr<glm::mat4> Camera::getViewProjectionMatrix() {
	return std::shared_ptr<mat4>(new mat4(projection * view));
}

void Camera::update() {
}

} /* namespace scene */
} /* namespace initial3d */
