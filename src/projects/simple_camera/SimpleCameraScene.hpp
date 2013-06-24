#ifndef SIMPLECAMERASCENE_H_
#define SIMPLECAMERASCENE_H_

#include <initial3d.hpp>
#include "SimpleTetrahedron.hpp"

using namespace initial3d::scene;

namespace initial3d {
namespace projects {
namespace simplecamera {

class SimpleCameraScene : public Scene {
public:
	SimpleCameraScene();
	virtual ~SimpleCameraScene();
	virtual void initAfterOpenGLLoaded();
	virtual void draw();
private:
	std::shared_ptr<Tetrahedron> simpleTetrahedronPtr;
};

}
}
} /* namespace initial3d */
#endif /* SIMPLECAMERASCENE_H_ */
