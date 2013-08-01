#ifndef SIMPLECAMERASCENE_H_
#define SIMPLECAMERASCENE_H_

#include <initial3d.hpp>

using initial3d::scene::Scene;
using initial3d::objects::ThreeDimensionsObject;

namespace initial3d {
namespace projects {
namespace simplecamera {

class SimpleCameraScene : public Scene {
public:
	SimpleCameraScene();
	virtual ~SimpleCameraScene();
	virtual void keyPressed(KeyCode keyCode);
	virtual void keyReleased(KeyCode keyCode);
private:
	std::shared_ptr<ThreeDimensionsObject> simpleTetrahedronPtr;
	bool toogleRotation = false;
};

}
}
} /* namespace initial3d */
#endif /* SIMPLECAMERASCENE_H_ */
