//
// Created by シルブー on 07/09/2021.
//

#include "Chat.h"

Chat::Chat(std::pair<User, User> users) : users(std::move(users)) {};
Chat::Chat(std::string first, std::string second) : users({first}, {second}) {};

bool Chat::operator==(const Chat &rhs) const {
    return (users == rhs.users || (users.first == rhs.users.second && users.second == rhs.users.first));
}

bool Chat::operator!=(const Chat &rhs) const {
    return !(rhs == *this);
}

void Chat::addMessage(const Message &message) {
    auto u1 = users.first;
    auto u2 = users.second;
    if(u1 == message.getSender() || u2 == message.getSender())
        messages.push_back(message);
}

void Chat::removeMessage(const Message &message) {
    messages.remove_if([=](auto to_remove) { return message == to_remove; });
}

size_t Chat::size() {
    return messages.size();
}

std::string Chat::toString(){
    std::string dump;
    dump += users.first.getUsername() + "  --  " + users.second.getUsername() + "\n";
    for (auto obj : messages) {
        dump += obj.toString() + "\n";
    }
    return dump;
}

