#include <iostream>

int main() {
  const int &r = 42;
  double p = 45.897;
  const int &q = p;
  std::cout << p << "\n";
  std::cout << q << "\n";
  std::cout << r << "\n";

  int err_numb = 0;
  const int *const currErr = &err_numb;
  std::cout << &err_numb << "\n";
  std::cout << currErr << "\n";
  std::cout << &currErr << "\n"; // address/reference of pointer, Pointer is an
                                 // object itself which points to something.
  std::cout << *(&currErr) << "\n";

  int *hello = &err_numb;
  std::cout << ++(*hello) << "\n";
  std::cout << ++(*hello) << "\n";
  std::cout << err_numb << "\n";
  return 0;
}