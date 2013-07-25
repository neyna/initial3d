#include "Sphere.hpp"

using glm::vec3;

namespace initial3d {
namespace objects {

void Sphere::computeOctahedron() {
	// creating the octahedron around the origin
	// we add 2 points per axis, on all axis. All adding to the origin the normalized direction vector of that axis
	// we add them triangle by triangle and in the correct order for face culling
	// all with x = 1
	data.clear();
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
}

vec3 Sphere::computeMiddle(const vec3& point1, const vec3& point2) {
	// compute the middle, no need to divide his length by 2 because we normalize it after
	vec3 middle1 = (point1 + point2);
	middle1 = middle1 * (radius / glm::length(middle1));
	return middle1;
}

void Sphere::computeSubdivision() {
	std::vector<glm::vec3> tmpData = std::vector<glm::vec3>(data.size() * 4);
	long triangleNumber = data.size() / 3;
	for (int i = 0; i < triangleNumber; ++i) {
		// take each triangle :
		// - compute the middle of each segment and modify its norm to make it radius far from the origin
		// - put the 3 new triangles in CCW in the data structure
		vec3 point1 = data[3*i];
		vec3 point2 = data[3*i+1];
		vec3 point3 = data[3*i+2];
		vec3 middle1 = computeMiddle(point1, point2);
		vec3 middle2 = computeMiddle(point2, point3);
		vec3 middle3 = computeMiddle(point1, point3);

		int baseIndex = 12 * i;
		tmpData[baseIndex] = point1;
		tmpData[baseIndex + 1] = middle1;
		tmpData[baseIndex + 2] = middle3;

		tmpData[baseIndex + 3] = middle3;
		tmpData[baseIndex + 4] = middle2;
		tmpData[baseIndex + 5] = point3;

		tmpData[baseIndex + 6] = middle1;
		tmpData[baseIndex + 7] = point2;
		tmpData[baseIndex + 8] = middle2;

		tmpData[baseIndex + 9] = middle1;
		tmpData[baseIndex + 10] = middle2;
		tmpData[baseIndex + 11] = middle3;
	}

	data = tmpData;
}

void Sphere::computeData() {
	computeOctahedron();

	for (int i = 0; i < numberOfSubdivision; i++) {
		computeSubdivision();
	}

	vertexNumber = data.size() * 3;
	glData.clear();
	for (vec3 point : data) {
		glData.push_back(point.x);
		glData.push_back(point.y);
		glData.push_back(point.z);
	}
	vertexPostionData = glData.data();
}

Sphere::Sphere(float radius, int numberOfSubdivision) : ThreeDimensionsObject(sizeof(GLfloat), 3), radius(radius),
		numberOfSubdivision(numberOfSubdivision) {
	computeData();
}

Sphere::~Sphere() {
}

void Sphere::draw(std::shared_ptr<glm::mat4>& modelViewProjectionMatrix) {
	// since we keep the inner model with a radius of 1.0f, we need to scale the object
//	glm::mat4 modelViewProjectionMatrixWithScale = modelViewProjectionMatrix * glm::scale(radius, radius, radius);
	ThreeDimensionsObject::draw(modelViewProjectionMatrix);
	//glm::mat4 myScalingMatrix = glm::scale(2.0f, 2.0f ,2.0f);
}

void Sphere::changeNumberOfSubdivision(int numberOfSubdivision) {
	this->numberOfSubdivision = numberOfSubdivision;
	computeData();
	renewOpenGLBuffers();
}

} /* namespace objects */
} /* namespace initial3d */
