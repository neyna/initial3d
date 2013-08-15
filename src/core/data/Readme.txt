Those files are used to generate ShaderLibrary.cpp.

But the generation is done only when calling cmake. So you must call Cmake in order to generate ShaderLibrary.cpp when you modify either of thoses files.
Or you can do : touch ../utils/ShadersLibrary.cpp.in

Todo : it could be interesting to code a small program to do the substitution in the build process instead of using Cmake. (but it's a bit overkill)