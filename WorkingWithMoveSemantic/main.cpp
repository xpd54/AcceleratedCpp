#include <iostream>
#include <string>

class Article {
private:
  std::string m_data;

public:
  Article(const std::string &resource) {
    if (&resource == &m_data) {
      std::cout << "<---Was Moved-->"
                << "\n";
    } else {
      std::cout << "<---Was Copied-->"
                << "\n";
    }
    std::cout << &resource << " " << &m_data << "\n";
  };
  Article(std::string &&resource) : m_data(std::move(resource)) {
    if (resource == "") {
      std::cout << "<---Was Moved-->"
                << "\n";
    } else {
      std::cout << "<---Was Copied-->"
                << "\n";
    }
    std::cout << &resource << " " << &m_data << "\n";
  };

  Article &operator=(Article &&rhs) {
    m_data = std::move(rhs.m_data);
    rhs.m_data = nullptr;
    return *this;
  }

  const std::string &get_content() const { return m_data; };
  void set_content(const std::string &content);
  ~Article(){};
};

int main() {
  Article news("hello how are you?");
  Article evening_news("Hello how are you this evening?");
  return 0;
}