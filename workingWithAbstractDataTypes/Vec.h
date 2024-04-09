#include <memory>
template <class T> class Vec {
public:
  typedef T *iterator;
  typedef const T *const_iterator;
  typedef size_t size_type;
  typedef T value_type;

  Vec() { create(); }
  explicit Vec(size_type n, const T &val = T()) { create(n, val); }

  Vec(const Vec &v) { create(v.begin(), v.end()); }; // copy constructor

  Vec &operator=(const Vec &);
  T &operator[](size_type i) { return data[i]; }
  const T &operator[](size_type i) const { return data[i]; }

  void push_back(const T &t) {
    if (avail == limit) {
      grow();
    }

    unchecked_append(t);
  }

  size_type size() const { return limit - data; }

  iterator begin() { return data; }
  const_iterator begin() const { return data; }

  iterator end() { return limit; }
  const_iterator end() const { return limit; }

  ~Vec() { uncreate(); }

private:
  T *data;
  T *avail;
  T *limit;

  std::allocator<T> alloc;

  void create();
  void create(size_type, const T &);
  void create(const_iterator, const_iterator);

  void uncreate();

  // support function for push_back
  void grow();
  void unchecked_append(const T &);
};
