#include <iostream>
#include <thread>

void takeArgument(const int &input) {
  std::cout << "Taking Argument :- " << input << "\n";
  std::cout << "Done taking argument"
            << "\n";
}

int main() {
  std::cout << "Start Passing argument"
            << "\n";
  std::thread takingArg(&takeArgument, 100);
  std::cout << "Done passing argument"
            << "\n";
  takingArg.join();
  return 0;
}