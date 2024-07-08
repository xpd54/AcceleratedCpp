#pragma once
#include "folder.h"
#include <set>
#include <string>
class Message {
  friend class Folder;

public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);            // copy constructor
  Message &operator=(const Message &); // copy assignment
  ~Message();                          // destructor

  void save(Folder &);
  void remove(Folder &);
  std::string getMessage() { return contents; }

private:
  std::string contents;       // actual message text
  std::set<Folder *> folders; // Folders that have the message
  // utility function used by copy constructor assignment and destructor
  void add_to_Folders(const Message &);
  void remove_from_Folders();
};

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folders(const Message &message) {
  for (auto folder : message.folders)
    folder->addMsg(this);
}

void Message::remove_from_Folders() {
  for (auto folder : folders)
    folder->remMsg(this);
  folders.clear();
}

Message::Message(const Message &message)
    : contents(message.contents), folders(message.folders) {
  add_to_Folders(message);
}

Message::~Message() { remove_from_Folders(); }

Message &Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}