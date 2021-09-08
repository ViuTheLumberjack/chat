//
// Created by シルブー on 07/09/2021.
//

#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H


#include <string>
#include <chrono>
#include "User.h"

class Message {
public:
    Message(const std::string &message, User &sender);

    bool operator==(const Message &rhs) const;
    bool operator!=(const Message &rhs) const;

    const std::string &getMessage() const;
    User& getSender() const;
    time_t getTimestamp() const;

    std::string toString();

private:
    std::string text;
    User& sender;
    time_t timestamp;
};


#endif //CHAT_MESSAGE_H
