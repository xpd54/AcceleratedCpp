#include <string>
class Screen {
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {
  } // contents have string initialized with lenght constructor

  char get() const { return contents[cursor]; } // implecitly inline
  inline char get(po)
  ~Screen();

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

