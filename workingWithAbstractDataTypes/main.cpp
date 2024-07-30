#include "StrVec.h"
#include <iostream>
#include <string>
void printStrVec(const StrVec &strVec) {
  std::string *firstPoint = strVec.begin();
  std::string *lastPoint = strVec.end();
  while (firstPoint != lastPoint) {
    std::cout << *firstPoint << "\n";
    ++firstPoint;
  }
}
int main() {
  StrVec container, holding, tempHolding;
  container.push_back("hello");
  container.push_back("hello world");
  holding = container;
  std::cout << holding.end() << "\n";
  return 0;
}