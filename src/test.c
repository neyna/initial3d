#include <stdio.h>
#include <stdlib.h>
#include <test.h>

int main (int argc, char *argv[]) {
  printf("Hello world !\n");
  fprintf(stdout,"Software version : %d.%d\n",
            Test_VERSION_MAJOR,
            Test_VERSION_MINOR);
  return 0;
}
