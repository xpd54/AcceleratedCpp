#include <string>
class Screen {
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c){};
  char get() const {
    return contents[cursor];
  } // implicitly inline as it's defined inline
  inline char get(pos ht, pos wd)
      const; // explicit inline means it will get inline when it's get defined
  Screen &move(pos r, pos c); // this can be make inline while making defination
  

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

inline Screen &Screen::move(pos r, pos c) { // r is row and c is column
  pos row = r + width;                      // compute the row location
  cursor = row + c;
  return *this;
}

// get is inine here as it's in declaration
char Screen::get(pos r, pos c) const {
  pos row = r + width; // compute row location
  return contents[row + c]; // return character at the given column
}


