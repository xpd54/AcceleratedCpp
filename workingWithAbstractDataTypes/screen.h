#pragma once

#include <string>
// class Window_mgr;
class Screen {

  // Try enabling only method for friend.
  //   friend void Window_mgr::clear(ScreenIndex);
  friend class Window_mgr;

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

  void some_member() const;

  Screen &set(char);
  Screen &set(pos row, pos column, char);

  Screen &display(std::ostream &os) {
    os << std::string("non const ");
    do_display(os);
    return *this;
  }

  const Screen &display(std::ostream &os) const {
    os << std::string("const ");
    do_display(os);
    return *this;
  }

private:
  mutable size_t access_ctr;
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos c) { // r is row and c is column
  pos row = r + width;                      // compute the row location
  cursor = row + c;
  return *this;
}

// get is inine here as it's in declaration
char Screen::get(pos r, pos c) const {
  pos row = r + width;      // compute row location
  return contents[row + c]; // return character at the given column
}

void Screen::some_member() const {
  ++access_ctr; // keep count of the call of any member function
}

Screen &Screen::set(char c) {
  contents[cursor] = c; // set a new value at curren cursor location
  return *this; // return this object as lvalue; (this is reference which is
                // rvalue)
}

Screen &Screen::set(pos row, pos column, char c) {
  contents[row * width + column] = c;
  return *this;
}

#include "window.h"
void Window_mgr::clear(ScreenIndex i) {
  // s is a reference to the screen we want to clear
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}