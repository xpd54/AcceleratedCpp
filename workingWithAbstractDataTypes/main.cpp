#include "message.h"
#include <iostream>
#include <string>
int main() {
  /*
  Sales_data default_value;
  Sales_data cin_vlaue(std::cin);
  print(std::cout, default_value) << "\n";
  print(std::cout, cin_vlaue) << "\n";
  */
  Folder holding("work");
  Message firstEmail("Hello How are you there");
  firstEmail.save(holding);
  Message copy = firstEmail;
  std::cout << copy.getMessage() << "\n";
  return 0;
}