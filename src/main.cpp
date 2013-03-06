#include "main.hpp"

using namespace initial3d;

int main(void) {

	Scene *scene = new Scene();
	Launcher *launcher = new GLFWLauncher();

	return launcher->run(scene);
}






