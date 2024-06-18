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
  Screen clientScreen(10, 10, 'a');
  clientScreen.set('#').display(std::cout);
  std::cout << "\n";
  const Screen blank(5, 3, '#');
  blank.display(std::cout);
  std::cout << "\n";
  return 0;
}