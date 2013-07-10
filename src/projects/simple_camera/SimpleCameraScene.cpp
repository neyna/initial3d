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
	sphereRunningCamera->horizontalSpeed = 0.1f;
	sphereRunningCamera->vecticalSpeed = -0.1f;

	simpleTetrahedronPtr = std::shared_ptr<ThreeDimensionsObject>(new ThreeDimensionsObject(
				stringPtr(new string("SimpleTetrahedronShader.vert")),	stringPtr(new string("SimpleTetrahedronShader.frag")),
				sizeof(GLfloat),														// size_t of vertices datatype
				sizeof(g_vertex_buffer_data) / sizeof(GLfloat),							// number of vertices
				3, 																		// number of data per vertex
				(void*) g_vertex_buffer_data 											// vertices data
				)
		);
	simpleTetrahedronPtr->addVertexColorData((void*)&g_color_buffer_data);

	addObject(simpleTetrahedronPtr);
}

SimpleCameraScene::~SimpleCameraScene() {
}

void SimpleCameraScene::keyPressed(KeyCode keyCode) {
	// TODO unitsToMove should increase when we got farther from the center
	const float unitsToMove = 0.5;
	SphereRunningCamera *sphereRunningCamera = (SphereRunningCamera*) (camera.get());
	switch(keyCode) {
	case KEY_SPACE:
		sphereRunningCamera->stopRotation();
		break;
	case KEY_65: //A
		sphereRunningCamera->continueRotation();
		break;
	case KEY_66: //B
		setWireFrameRendering(true);
		break;
	case KEY_RIGHT:
		sphereRunningCamera->moveRight(unitsToMove);
		break;
	case KEY_LEFT:
		sphereRunningCamera->moveLeft(unitsToMove);
		break;
	case KEY_UP:
		sphereRunningCamera->moveUp(unitsToMove);
		break;
	case KEY_DOWN:
		sphereRunningCamera->moveDown(unitsToMove);
		break;
	default:
		break;
	}
}

void SimpleCameraScene::keyReleased(KeyCode keyCode) {
		switch(keyCode) {
		default:
			break;
		}
}

}
}
} /* namespace initial3d */
