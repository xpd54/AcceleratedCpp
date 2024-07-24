#include <iostream>
#include <string>

// Defining class to act like value.
class HasPtr {
private:
  std::string *ps;
  int i;

public:
  /*
   * constructor if given string or default it's empty. Stores Pointer of it so
   * it's in heap. Initialize i with 0.
   *
   */
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

  /*
   * copy constructor make copy it also make new copy of given string and stores
   * pointer location of it.
   */
  HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}

  HasPtr &operator=(const HasPtr &rhs) {
    std::cout << "making copy of " << *rhs.ps << "\n";
    auto newps = new std::string(*rhs.ps); // make a copy of underlying string
    delete ps; // free the old memory. In case of self assignment we already
               // made a copy of string which should prevent deleting string
               // from both *this and rhs.
    ps = newps;
    i = rhs.i;
    return *this;
  };
  void Print() {
    std::cout << "i :- " << i << " "
              << "ps :- " << *ps << "."
              << "psr :- " << ps << "."
              << "\n";
  }
  ~HasPtr() { delete ps; }
};

// Class which act like a pointer

// for this we need our copy construcotr and copy assignment operator to copy
// the pointer memeber not the string.

class HasActPtr {
private:
  std::string *ps; // holds string in dynamic memory
  int i;
  std::size_t *use; // member to keep track of how many object shares *ps
public:
  // constructor allocate new string and new counter which is set to 1;
  HasActPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
  // copy constructor copy all 3 data member with incement use
  // copy will point to same copy of string
  HasActPtr(const HasActPtr &hasActPtr)
      : ps(hasActPtr.ps), i(hasActPtr.i), use(hasActPtr.use) {
    ++*use;
  }

  void Print() {
    std::cout << "i :- " << i << " "
              << "ps :- " << *ps << ". "
              << "psr :- " << ps << "."
              << "\n";
  }

  // copy assignment operator
  // will point to same string resource but increse the counter;
  HasActPtr &operator=(const HasActPtr &rhs) {
    std::cout << "reference count before :- " << *rhs.use << " " << *use << "\n";
    ++*rhs.use;        // right hand side refernece will increase as it's gettin
                       // assigned to another ref; It will get handled (--) when
                       // assigning to left side
    if (--*use == 0) { // this operation decrease a reference count and check
                       // this one same as
                       // int a = --*use; if(a ==0)
      delete ps;
      delete use;
    }

    std::cout << "reference count after :- " << *use << "\n";

    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
  }
  ~HasActPtr() {
    if (--*use == 0) {
      delete ps;
      delete use;
    }
  };
};

int main() {
  HasActPtr firstValue("Hello World");
  HasActPtr secondValue;
  HasActPtr thirdValue;
  HasActPtr fourthValue;
  secondValue = firstValue;
  thirdValue = firstValue;
  fourthValue = firstValue;
  firstValue = firstValue;
  //   thirdValue.Print();
  //   firstValue.Print();
  //   secondValue.Print();
  return 0;
}