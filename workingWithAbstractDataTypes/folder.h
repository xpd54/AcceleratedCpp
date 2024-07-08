#pragma once
#include <set>
class Message;
class Folder {
private:
  /* data */
  std::set<Message *> messages;

public:
  void addMsg(Message *);
  void remMsg(Message *);
  Folder(/* args */);
  ~Folder();
};
