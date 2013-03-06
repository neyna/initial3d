#include <stdio.h>
#include <stdlib.h>
#include <version.hpp>

void print_version() {
  fprintf(stdout,"Software version : %d.%d\n",
		  INITIAL3D_VERSION_MAJOR,
		  INITIAL3D_VERSION_MINOR);
}

char* getVersion() {
	char* buff = (char*)malloc(100*sizeof(char));
	sprintf(buff, "Software version : %d.%d", INITIAL3D_VERSION_MAJOR, INITIAL3D_VERSION_MINOR);
	return buff;
}
