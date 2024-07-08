#pragma once
#include <set>
#include <string>
class Message;
class Folder {
private:
  std::string name;
  /* data */
  std::set<Message *> messages;

public:
  void addMsg(Message *);
  void remMsg(Message *);
  Folder(std::string identifire) : name(identifire) {}

  Folder(const Folder &);
  Folder &operator=(const Folder &rhs);
  ~Folder();
};

void Folder::addMsg(Message *message) { messages.insert(message); }

void Folder::remMsg(Message *message) { messages.erase(message); }
Folder::~Folder() {
    messages.clear();
}