#include <iostream>
#include <string>

class Article {
private:
  std::string m_data;

public:
  Article(){};
  Article(const std::string &resource) : m_data(resource) {
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
    return *this;
  }

  Article &operator=(Article &rhs) {
    m_data = std::move(rhs.m_data);
    return *this;
  }

  Article(const Article &other) : m_data(other.m_data) {
    std::cout << "<---Copy Constructor Called--->"
              << "\n";
  }

  Article(Article &&other) : m_data(std::move(other.m_data)) {
    std::cout << "<---Move Constructor Called--->" << "\n";
    other.m_data.clear();
  }


  const std::string &get_content() const { return m_data; };
  void set_content(const std::string &content);
  ~Article(){};
};

std::string getNews() { return std::string("hello how are you?"); }

std::string getEveningNews() {
  return std::string("Hello how are you this evening?");
}

Article getArticle() {
  Article hello_to_local("Hello To local");
  return hello_to_local;
}

int main() {
  std::string hello("hello");
  Article news(getNews());
  Article evening_news(getEveningNews());
  Article *morning_news = new Article(hello);
  std::cout << morning_news->get_content() << "\n";
  Article document;
  document = getArticle();
  return 0;
}