#include "lorem.h"

extern "C" bool lorem(int integer)
{
  if (integer > 4)
    return true;

  return false;
}
