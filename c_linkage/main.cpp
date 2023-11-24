#include "lorem.hpp"

#include <cstdlib>
#include <cstdio>

int main()
{
  printf("%s\n", lorem(3) ? "true" : "false");
  return EXIT_SUCCESS;
}
