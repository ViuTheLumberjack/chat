//
// Created by シルブー on 07/09/2021.
//

#ifndef CHAT_CHAT_H
#define CHAT_CHAT_H


#include <list>
#include "User.h"
#include "Message.h"

class Chat {
public:
    Chat(std::pair<User, User> users);
    Chat(std::string first, std::string second);

    bool operator==(const Chat &rhs) const;
    bool operator!=(const Chat &rhs) const;

    void addMessage(const Message &message);
    void removeMessage(const Message &message);
    size_t size();

    void readMessage(Message &message);
    void readAll();
    int countUnread();

    std::string toString();

private:
    std::pair<User, User> users;
    std::list<Message> messages;
};

#endif //CHAT_CHAT_H
