// dice roller

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void ) {
  srand(time(NULL));

  int num = (rand( ) % 6) + 1;
  printf("%d\n", num);

  return 0;
} //end main
