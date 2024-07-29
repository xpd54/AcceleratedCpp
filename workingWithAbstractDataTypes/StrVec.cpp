#include "StrVec.h"
#include <memory>
std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
  // first allocate the sapce which can holds in the range
  auto data = alloc.allocate(e - b);
  // return pair by data and uninitialized_copy
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  // if elements are 0 no work needed and we pointed elements to nullptr
  if (elements) {
    for (auto p = first_free; p != elements;) {
      alloc.destroy(--p);
    }
    // deallocate the memory which is empty and
    alloc.deallocate(elements, cap - elements);
  }
}

StrVec::StrVec(const StrVec &s) {
  auto newData = alloc_n_copy(s.begin(), s.end());
  elements = newData.first; // alloc_n_copy is pair
  first_free = cap = newData.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  // free which is holding in lhs
  free();
  first_free = cap = data.second;
  return *this;
}