#include "lorem.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("%s\n", lorem(3) ? "true" : "false");
  return EXIT_SUCCESS;
}
