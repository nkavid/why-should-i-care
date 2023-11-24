#include "output/foobar.pb.h"

#include <iostream>
#include <string>

int main()
{
  lorem::Baz baz{};
  
  baz.set_someinteger(64);
  baz.set_somestring("wololo");

  std::string buffer{};
  assert(baz.SerializeToString(&buffer));

  std::cout << buffer << '\n';
  
  return EXIT_SUCCESS;
}
