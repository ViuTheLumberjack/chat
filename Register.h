//
// Created by シルブー on 07/09/2021.
//

#ifndef CHAT_REGISTER_H
#define CHAT_REGISTER_H

class Chat;

#include "Chat.h"
#include <list>
#include "Observer.h"

// could be a Singleton
class Register : public Observer{
public:
    Register() = default;

    void addChat(Chat &chat);
    void removeChat(Chat &chat);
    void addMessage(const Message &msg, Chat &c);
    size_t size() const;

    void update(const Message &msg) override;

    std::string toString();

    ~Register() override = default;

private:
    std::list<Chat> buffer;
};


#endif //CHAT_REGISTER_H
