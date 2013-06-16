#ifndef ALL_INCLUDES_HPP_
#define ALL_INCLUDES_HPP_

// TODO : generate all project includes via Cmake like version.hpp
// is it possible ??? We have dependency order like Launcher depends on WindowProperties
// it is if we use forward declare of all project class used

#include "standard_includes.hpp"
#include <version.hpp>

#include "exception/Initial3dException.hpp"

#include "objects/ThreeDimensionObject.hpp"

#include "scene/Camera.hpp"
#include "scene/Scene.hpp"

#include "system/WindowProperties.hpp"
#include "system/Launcher.hpp"
#include "system/GLFWLauncher.hpp"

#include "utils/FPSTimer.hpp"
#include "utils/ShaderLoader.hpp"



#endif /* ALL_INCLUDES_HPP_ */
