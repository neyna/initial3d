#include <stdio.h>
#include <stdlib.h>
#include <version.h>

void print_version() {
  fprintf(stdout,"Software version : %d.%d\n",
		  INITIAL3D_VERSION_MAJOR,
		  INITIAL3D_VERSION_MINOR);
}
