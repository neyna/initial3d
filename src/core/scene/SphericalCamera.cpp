#include "../initial3d.hpp"

namespace initial3d {
namespace scene {

SphericalCamera::SphericalCamera(const glm::vec3 &initialPosition, const glm::vec3 &lookAtPoint)
	: position(initialPosition), lookAtPoint(lookAtPoint) {
	// compute radius
	radius = sqrt(
			pow(initialPosition.x - lookAtPoint.x, 2)
					+ pow(initialPosition.y - lookAtPoint.y, 2)
					+ pow(initialPosition.z - lookAtPoint.z, 2));

	// compute theta and phi using formulae
	// (1) x = radius * sin(theta)*cos(phi)
	// (2) y = radius * sin(theta)*sin(phi)
	// (3) z = radius * cos(theta)

	// using (3)
	theta = acos(position.z / radius);
	// using (1)
	// todo if sin(theta = 0)
	phi = acos((position.x / radius) / sin(theta));
}

SphericalCamera::~SphericalCamera() {

}

} /* namespace projects */
} /* namespace initial3d */
