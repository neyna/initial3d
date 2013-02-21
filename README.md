Readme.

License : GPL

To generate eclipse projects :
  cd [....]/initial3d/..
  mkdir build
  cd build 
  cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE -D CMAKE_BUILD_TYPE=Debug ../initial3d
This generated 2 projects, one for sources and one with all to build and run


TODO:
check if really GLFW 7+ is needed for OpenGL 3.3+ Context 

