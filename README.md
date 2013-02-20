Readme.

License : GPL

To generate eclipse projects :
  cd [....]/initial3d/..
  mkdir build
  cd build 
  cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE -D CMAKE_BUILD_TYPE=Debug ../initial3d
This generated 2 projects, one for sources and one with all to build and run

