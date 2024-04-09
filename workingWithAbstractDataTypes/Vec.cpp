#include "Vec.h"
#include <algorithm>
#include <iostream>
template <class T> void Vec<T>::create() {
  data = 0;
  avail = 0;
  limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T &val) {
  data = alloc.allocate(n);
  limit = data + n;
  avail = data + n;
  std::uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j) {
  data = alloc.allocate(j - i);
  limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate() {
  if (data) {
    iterator it = avail;
    while (it != data) {
      alloc.destroy(--it);
    }

    alloc.deallocate(data, limit - data);
  }
  data = limit = avail = 0;
}

template <class T> void Vec<T>::grow() {
  size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));

  iterator new_data = alloc.allocate(new_size);
  iterator new_avail = std::uninitialized_copy(data, avail, new_data);
  uncreate();

  data = new_data;
  avail = new_avail;
  limit = data + new_size;
}

template <class T> void Vec<T>::unchecked_append(const T &val) {
  alloc.construct(avail++, val);
}
