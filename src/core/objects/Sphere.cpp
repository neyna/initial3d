#include "Sphere.hpp"

using glm::vec3;

namespace initial3d {
namespace objects {

Sphere::Sphere(float radius) : ThreeDimensionsObject(sizeof(GLfloat), 3), radius(radius) {
	// creating the octahedron around the origin
	vec3 origin = vec3(0.0f, 0.0f, 0.0f);
	// we add 2 points per axis, on all axis. All adding to the origin the normalized direction vector of that axis
	// we add them triangle by triangle and in the correct order for face culling
	// all with x = 1
	data.push_back(vec3(1, 0, 0));
	data.push_back(vec3(0, 0, 1));
	data.push_back(vec3(0, -1, 0));

	data.push_back(vec3(1, 0, 0));
	data.push_back(vec3(0, 1, 0));
	data.push_back(vec3(0, 0, 1));

	data.push_back(vec3(1, 0, 0));
	data.push_back(vec3(0, -1, 0));
	data.push_back(vec3(0, 0, -1));

	data.push_back(vec3(1, 0, 0));
	data.push_back(vec3(0, 0, -1));
	data.push_back(vec3(0, 1, 0));

	// all with x = -1 (all we need to do is to invert the second and third point from previous definitions after setting first x to -1)
	data.push_back(vec3(-1, 0, 0));
	data.push_back(vec3(0, -1, 0));
	data.push_back(vec3(0, 0, 1));

	data.push_back(vec3(-1, 0, 0));
	data.push_back(vec3(0, 0, 1));
	data.push_back(vec3(0, 1, 0));

	data.push_back(vec3(-1, 0, 0));
	data.push_back(vec3(0, 0, -1));
	data.push_back(vec3(0, -1, 0));

	data.push_back(vec3(-1, 0, 0));
	data.push_back(vec3(0, 1, 0));
	data.push_back(vec3(0, 0, -1));

	//todo : compute subdivisions

	vertexNumber = 8 * 3 * 3;
	glData.reset(new std::vector<GLfloat>(0));

	for(vec3 point : data) {
		glData->push_back(point.x);
		glData->push_back(point.y);
		glData->push_back(point.z);
	}
	vertexPostionData = glData->data();

}

Sphere::~Sphere() {
}

void Sphere::draw(std::shared_ptr<glm::mat4>& modelViewProjectionMatrix) {
	// since we keep the inner model with a radius of 1.0f, we need to scale the object
//	glm::mat4 modelViewProjectionMatrixWithScale = modelViewProjectionMatrix * glm::scale(radius, radius, radius);
	ThreeDimensionsObject::draw(modelViewProjectionMatrix);
	//glm::mat4 myScalingMatrix = glm::scale(2.0f, 2.0f ,2.0f);
}

} /* namespace objects */
} /* namespace initial3d */
