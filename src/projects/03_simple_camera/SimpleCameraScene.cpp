#include "SphereRunningCamera.hpp"
#include "SimpleCameraScene.hpp"

using namespace std;
using namespace initial3d::system;
using namespace glm;

namespace initial3d {
namespace projects {
namespace simplecamera {

static const GLfloat g_vertex_buffer_data[] = {
		// 1st triangle
		0.0f,  1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		// 2nd
		0.0f,  1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, -1.0f, -1.0f,
		// 3rd
		0.0f,  1.0f, 0.0f,
		0.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 0.0f,
		// bottom
		-1.0f, -1.0f, 0.0f,
		0.0f, -1.0f, -1.0f,
		1.0f, -1.0f, 0.0f,
	};

static const GLfloat g_color_buffer_data[] = {
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.9f, 0.4f, 0.3f,
		0.1f, 0.6f, 0.5f,
		0.3f, 0.8f, 0.7f,
};

SimpleCameraScene::SimpleCameraScene() : Scene(shared_ptr<Camera>(new SphereRunningCamera())) {
	SphereRunningCamera *sphereRunningCamera = (SphereRunningCamera*) (camera.get());

	simpleTetrahedronPtr = std::shared_ptr<ThreeDimensionsObject>(new ThreeDimensionsObject(
				sizeof(GLfloat),														// size_t of vertices datatype
				3 																		// number of data per vertex
				)
		);
	simpleTetrahedronPtr->setVertexData((void*) g_vertex_buffer_data, sizeof(g_vertex_buffer_data) / sizeof(GLfloat));
	simpleTetrahedronPtr->setVertexColorData((void*)&g_color_buffer_data);

	addObject(simpleTetrahedronPtr);
}

SimpleCameraScene::~SimpleCameraScene() {
}

void SimpleCameraScene::keyPressed(KeyCode keyCode) {
	Scene::keyPressed(keyCode);
	SphereRunningCamera *sphereRunningCamera = (SphereRunningCamera*) (camera.get());
	switch(keyCode) {
	case KEY_SPACE:
		sphereRunningCamera->setRotating(toogleRotation);
		toogleRotation = !toogleRotation;
		break;
	case KEY_66: //B
		toggleWireFrameRendering();
		break;
	default:
		break;
	}
}

void SimpleCameraScene::keyReleased(KeyCode keyCode) {
	Scene::keyReleased(keyCode);
		switch(keyCode) {
		default:
			break;
		}
}

}
}
} /* namespace initial3d */
