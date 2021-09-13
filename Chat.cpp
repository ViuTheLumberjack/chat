//
// Created by シルブー on 07/09/2021.
//

#include <algorithm>
#include <stdexcept>
#include "Chat.h"

Chat::Chat(std::pair<User, User> users) : users(std::move(users)) {};
Chat::Chat(std::string first, std::string second) : users({first}, {second}) {};

bool Chat::operator==(const Chat &rhs) const {
    return (users == rhs.users || (users.first == rhs.users.second && users.second == rhs.users.first));
}

bool Chat::operator!=(const Chat &rhs) const {
    return !(rhs == *this);
}

// add Exception
void Chat::addMessage(const Message &message) {
    auto u1 = users.first;
    auto u2 = users.second;
    if(u1 == message.getSender() || u2 == message.getSender())
        messages.push_back(message);
    else throw std::invalid_argument("Inserito Utente non appartenente alla chat");

    notifyObservers(message);
}

void Chat::removeMessage(const Message &message) {
    messages.remove_if([=](auto to_remove) { return message == to_remove; });
}

size_t Chat::size() {
    return messages.size();
}

void Chat::readMessage(Message &message) {
    message.setRead(true);
}

void Chat::readAll(){
    for (auto &item : messages){
        if(!item.isRead())
            item.setRead(true);
    }
}

int Chat::countUnread(){
    int unreadMessages = static_cast<int>(std::count_if(messages.begin(), messages.end(), [](const Message &msg) { return !msg.isRead(); }));
    return unreadMessages;
}

void Chat::notifyObservers(const Message &msg) {
    testMock = !testMock;
    for (auto observer : obs) {
        observer.update(msg);
    }
}

void Chat::attachObserver(Observer &o) {
    obs.push_back(o);
}

void Chat::detachObserver(Observer &o) {
    obs.remove(o);
}

size_t Chat::getObserverNum() {
    return obs.size();
}

std::string Chat::toString(){
    std::string dump;
    dump += users.first.getUsername() + "  --  " + users.second.getUsername() + "\n";
    for (auto obj : messages) {
        dump += obj.toString() + "\n";
    }
    return dump;
}
