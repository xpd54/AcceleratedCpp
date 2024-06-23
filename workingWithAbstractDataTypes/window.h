#pragma once
#include "screen.h"
#include <vector>
class Window_mgr {
public:
  // location Id for each screen on the window
  using ScreenIndex = std::vector<Screen>::size_type;
  // reset the Screen at the given position to all blanks
  void clear(ScreenIndex);

private:
  // window have a vector called screens which hold more than one screen
  // by default it have one screen
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
  // s is a reference to the screen we want to clear
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}