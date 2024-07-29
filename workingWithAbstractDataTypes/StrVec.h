/*
  This StrVec holds string which means it's a vector which holds string pointer
  in an array Due to that all elements and first_free cap is actually an ponter
  to string.
*/
#include <string>

class StrVec {
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);              // copy constructor
  StrVec &operator=(const StrVec &);   // copy assignment
  ~StrVec();                           // destructor
  void push_back(const std::string &); // copy the elements
  size_t size() { return first_free - elements; }
  size_t capacity() { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

private:
  static std::allocator<std::string> alloc; // allocate the elements
  void chk_n_alloc() {
    if (size() == capacity())
      reallocate();
  }
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();
  void reallocate();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};
