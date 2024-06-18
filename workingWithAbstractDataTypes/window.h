#pragma once
#include "screen.h"
#include <vector>
class Window_mgr {
private:
  // window have a vector called screens which hold more than one screen
  // by default it have one screen
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};
