#include "salesData.h"
#include "screen.h"
#include <iostream>
#include <string>
int main() {
  /*
  Sales_data default_value;
  Sales_data cin_vlaue(std::cin);
  print(std::cout, default_value) << "\n";
  print(std::cout, cin_vlaue) << "\n";
*/
  Screen clientScreen;
  char ch = clientScreen.get();
  std::cout << ch << "\n";
  std::cout << "with over loaded " << clientScreen.get(0, 0) << "\n";

  return 0;
}