#ifndef ALL_INCLUDES_HPP_
#define ALL_INCLUDES_HPP_

// TODO : generate all project includes via Cmake like version.hpp
// is it possible ??? We have dependency order like Launcher depends on WindowProperties
// it is if we use forward declare of all project class used

#include "standard_includes.hpp"

namespace initial3d {
	typedef std::shared_ptr<std::string> stringPtr;
	//template<typename _Tp> using strvector = std::vector<_Tp>;
	/**
	 * Keys 0 to 255 are received from keyboard using encoding ISO-8859-1 (Latin 1)
	 */
	enum KeyCode {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, KEY_11, KEY_12, KEY_13, KEY_14, KEY_15, KEY_16, KEY_17, KEY_18, KEY_19, KEY_20, KEY_21, KEY_22, KEY_23, KEY_24, KEY_25, KEY_26, KEY_27, KEY_28, KEY_29, KEY_30, KEY_31, KEY_32, KEY_33, KEY_34, KEY_35, KEY_36, KEY_37, KEY_38, KEY_39, KEY_40, KEY_41, KEY_42, KEY_43, KEY_44, KEY_45, KEY_46, KEY_47, KEY_48, KEY_49, KEY_50, KEY_51, KEY_52, KEY_53, KEY_54, KEY_55, KEY_56, KEY_57, KEY_58, KEY_59, KEY_60, KEY_61, KEY_62, KEY_63, KEY_64, KEY_65, KEY_66, KEY_67, KEY_68, KEY_69, KEY_70, KEY_71, KEY_72, KEY_73, KEY_74, KEY_75, KEY_76, KEY_77, KEY_78, KEY_79, KEY_80, KEY_81, KEY_82, KEY_83, KEY_84, KEY_85, KEY_86, KEY_87, KEY_88, KEY_89, KEY_90, KEY_91, KEY_92, KEY_93, KEY_94, KEY_95, KEY_96, KEY_97, KEY_98, KEY_99, KEY_100, KEY_101, KEY_102, KEY_103, KEY_104, KEY_105, KEY_106, KEY_107, KEY_108, KEY_109, KEY_110, KEY_111, KEY_112, KEY_113, KEY_114, KEY_115, KEY_116, KEY_117, KEY_118, KEY_119, KEY_120, KEY_121, KEY_122, KEY_123, KEY_124, KEY_125, KEY_126, KEY_127, KEY_128, KEY_129, KEY_130, KEY_131, KEY_132, KEY_133, KEY_134, KEY_135, KEY_136, KEY_137, KEY_138, KEY_139, KEY_140, KEY_141, KEY_142, KEY_143, KEY_144, KEY_145, KEY_146, KEY_147, KEY_148, KEY_149, KEY_150, KEY_151, KEY_152, KEY_153, KEY_154, KEY_155, KEY_156, KEY_157, KEY_158, KEY_159, KEY_160, KEY_161, KEY_162, KEY_163, KEY_164, KEY_165, KEY_166, KEY_167, KEY_168, KEY_169, KEY_170, KEY_171, KEY_172, KEY_173, KEY_174, KEY_175, KEY_176, KEY_177, KEY_178, KEY_179, KEY_180, KEY_181, KEY_182, KEY_183, KEY_184, KEY_185, KEY_186, KEY_187, KEY_188, KEY_189, KEY_190, KEY_191, KEY_192, KEY_193, KEY_194, KEY_195, KEY_196, KEY_197, KEY_198, KEY_199, KEY_200, KEY_201, KEY_202, KEY_203, KEY_204, KEY_205, KEY_206, KEY_207, KEY_208, KEY_209, KEY_210, KEY_211, KEY_212, KEY_213, KEY_214, KEY_215, KEY_216, KEY_217, KEY_218, KEY_219, KEY_220, KEY_221, KEY_222, KEY_223, KEY_224, KEY_225, KEY_226, KEY_227, KEY_228, KEY_229, KEY_230, KEY_231, KEY_232, KEY_233, KEY_234, KEY_235, KEY_236, KEY_237, KEY_238, KEY_239, KEY_240, KEY_241, KEY_242, KEY_243, KEY_244, KEY_245, KEY_246, KEY_247, KEY_248, KEY_249, KEY_250, KEY_251, KEY_252, KEY_253, KEY_254, KEY_255,
					KEY_ESC, KEY_SPACE, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_UNKNOWN};
}

#include <version.hpp>

#include "exception/Initial3dException.hpp"

#include "objects/ThreeDimensionObject.hpp"

#include "scene/Camera.hpp"
#include "scene/SphericalCamera.hpp"
#include "scene/Scene.hpp"

#include "system/System.hpp"
#include "system/WindowProperties.hpp"
#include "system/Launcher.hpp"
#include "system/GLFWLauncher.hpp"

#include "utils/FPSTimer.hpp"
#include "utils/ShaderLoader.hpp"
#include "utils/OpenGLUtils.hpp"






#endif /* ALL_INCLUDES_HPP_ */
