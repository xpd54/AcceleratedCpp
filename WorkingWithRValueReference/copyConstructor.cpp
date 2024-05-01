#include <array>
#include <iostream>
#include <vector>
#define WIDETH 4
class BitMap {
private:
  // screen is 8 segment width
  std::vector<std::array<size_t, WIDETH>> screen;

public:
  BitMap() = default;
  BitMap(const std::vector<std::array<size_t, WIDETH>> &input)
      : screen(input) {}
  BitMap(const BitMap &other) : screen(other.screen) {
    std::cout << "Copied"
              << "\n";
  }

  BitMap &operator=(BitMap &rhs) {
    std::cout << "Operator only lvalue"
              << "\n";
    screen = rhs.screen;
    return *this;
  }

  BitMap &operator=(const BitMap &rhs) {
    std::cout << "Operator lvalue and ravalue"
              << "\n";
    screen = rhs.screen;
    return *this;
  }

  BitMap &operator=(BitMap &&rhs) {
    std::cout << "Operator only rvalue"
              << "\n";
    screen = rhs.screen;
    return *this;
  }

  void print() {
    for (std::array<size_t, WIDETH> &line : screen) {
      for (const size_t &bit : line) {
        std::cout << bit << " ";
      }
      std::cout << "\n";
    }
  }
  ~BitMap() {
    std::cout << "Clear"
              << "\n";
    screen.clear();
  }
};

// returning r value;
BitMap foobar() {
  BitMap renderable({{1, 2, 3, 4}, {1, 3, 4, 5}, {0, 0, 0, 0}});
  return renderable;
}

template <typename T> void swap(T &a, T &b) {
  T temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

int main() {
  BitMap renderable({{1, 2, 3, 4}, {1, 3, 4, 5}, {5, 5, 3, 2}});
  BitMap renderable_moved({{1, 2, 3, 4}});
  BitMap copy_renderable;

  std::cout << "----------------- only r value------------"
            << "\n";
  copy_renderable = foobar();
  copy_renderable.print();
  std::cout << "----------------- only l value------------"
            << "\n";
  copy_renderable = renderable;

  copy_renderable.print();
  return 0;
}