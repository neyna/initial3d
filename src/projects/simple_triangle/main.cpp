#include "../../all_includes.hpp"
#include "SimpleTriangleScene.hpp"

using namespace initial3d;

int main(void) {

	Scene *scene = new SimpleTriangleScene();
	Launcher *launcher = new GLFWLauncher(scene);

	return launcher->run();
}






