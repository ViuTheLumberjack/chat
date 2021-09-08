//
// Created by シルブー on 07/09/2021.
//

#ifndef CHAT_REGISTER_H
#define CHAT_REGISTER_H

#include "Chat.h"
#include <list>

// could be a Singleton
class Register {
public:
    Register() = default;

    void addChat(const Chat &chat);
    void removeChat(const Chat &chat);
    size_t size();

    std::string toString();

private:
    std::list<Chat> buffer;
};


#endif //CHAT_REGISTER_H
