#include <iostream>
#include <string>

class Article {
private:
  std::string m_data;

public:
  Article(const std::string &resource) : m_data(resource) {
    std::cout << &resource << " " << &m_data << "\n";
  };
  const std::string &get_content() const { return m_data; };
  void set_content(const std::string &content);
  ~Article(){};
};

int main() {
  std::string morning_news("hello how are you?");
  std::string evening_news = morning_news;
  std::cout << &morning_news << " " << &evening_news << "\n";
  Article news(morning_news);
  std::cout << news.get_content() << "\n";
  return 0;
}