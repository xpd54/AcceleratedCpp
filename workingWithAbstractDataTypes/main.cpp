#include "salesData.h"
#include <iostream>
#include <string>
int main() {
  Sales_data default_value;
  Sales_data cin_vlaue(std::cin);
  print(std::cout, default_value) << "\n";
  print(std::cout, cin_vlaue) << "\n";
  return 0;
}