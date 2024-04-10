#include "Vec.h"
#include <iostream>
int main() {
  Vec<int> test;
  test.push_back(10);
  test.push_back(200);
  std::cout << *test.begin() << " " << *(test.end() - 1) << "\n";
  std::cout << "Hello"
            << "\n";
}