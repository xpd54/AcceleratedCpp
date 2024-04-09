template <class T> class Vec {
public:
  typedef T *iterator;
  typedef const T *const_iterator;
  typedef size_t size_type;
  typedef T value_type;

  Vec(const Vec &v){create(v.begin(), v.end())}; // copy constructor

  Vec() { create(); }
  explicit Vec(size_type n, constT &val = T()) { create(n, val); }

  size_type size() const { return limit - data; }

  T &operator[](size_type i) { return data[i]; }
  const T &operator[](size_type i) const { return data[i]; }

  Vec &operator=(const Vec &);

  iterator begin() { return data; }
  const_iterator begin() const { return data; }

  iterator end() { return limit; }
  const_iterator end() const { return limit; }

private:
  T *data;
  T *limit;
};
