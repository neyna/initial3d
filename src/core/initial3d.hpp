#ifndef ALL_INCLUDES_HPP_
#define ALL_INCLUDES_HPP_

// TODO : generate all project includes via Cmake like version.hpp
// is it possible ??? We have dependency order like Launcher depends on WindowProperties
// it is if we use forward declare of all project class used

#include "initial3d_basics.hpp"

#include "exception/Initial3dException.hpp"

#include "controls/ControlHandler.hpp"
#include "controls/SphericalCameraControlHandler.hpp"

#include "utils/ShadersLibrary.hpp"
#include "objects/ThreeDimensionsObject.hpp"
#include "objects/Sphere.hpp"

#include "scene/Camera.hpp"
#include "scene/SphericalCamera.hpp"
#include "scene/Scene.hpp"

#include "system/FontRenderer.hpp"
#include "utils/GameInformation.hpp"
#include "utils/GameInformations.hpp"

#include "system/System.hpp"
#include "system/WindowProperties.hpp"
#include "system/Launcher.hpp"
#include "system/GLFWLauncher.hpp"

#include "utils/FPSTimer.hpp"
#include "utils/ShaderLoader.hpp"
#include "utils/OpenGLUtils.hpp"



#endif /* ALL_INCLUDES_HPP_ */
