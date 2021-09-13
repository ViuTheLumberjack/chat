//
// Created by シルブー on 07/09/2021.
//

#ifndef CHAT_CHAT_H
#define CHAT_CHAT_H


#include <list>
#include "User.h"
#include "Message.h"
#include "Subject.h"

class Chat : public Subject{
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

    //updates this variable to test the observer
    bool testMock = false;
    void notifyObservers(const Message &msg) override;
    void attachObserver(Observer &o) override;
    void detachObserver(Observer &o) override;

    size_t getObserverNum();

    std::string toString();

private:
    std::pair<User, User> users;
    std::list<Message> messages;
    //std::list<Observer> obs;
};

#endif //CHAT_CHAT_H
