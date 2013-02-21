#include <stdio.h>
#include <stdlib.h>
#include <version.h>

void print_version() {
  fprintf(stdout,"Software version : %d.%d\n",
            TEST_VERSION_MAJOR,
            TEST_VERSION_MINOR);
}
