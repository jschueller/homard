#include "utilities.h"
#include <iostream>
int main()
{
  MESSAGE("using MESSAGE ok" );
  std::cout << "try_link_kernel cout"<<std::endl;
  std::cerr << "try_link_kernel cerr"<<std::endl;
  return 0;
}
