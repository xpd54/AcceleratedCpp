#include "Vec.h"
#include <iostream>
#include <string>
int main() {
  Vec<int> test;
  test.push_back(10);
  test.push_back(200);
  std::cout << *test.begin() << " " << *(test.end() - 1) << "\n";

  Vec<std::string> message;
  message.push_back("Hello");
  message.push_back("world");

  std::cout << *message.begin() << " " << *(message.end() - 1) << "\n";
}