//
// Created by シルブー on 07/09/2021.
//

#include "Register.h"
#include <algorithm>
#include <iostream>

bool Register::operator==(const Observer &rhs) {
    return static_cast<Observer>(*this) == rhs;
}

void Register::addChat(Chat &chat) {
    if(std::find(buffer.begin(), buffer.end(), chat) == buffer.end()){
        buffer.push_back(chat);
        chat.attachObserver(*this);
    }
}

void Register::removeChat(Chat &chat) {
    buffer.remove_if([=](auto to_remove) {
        if (chat == to_remove) to_remove.detachObserver(*this);
        return chat == to_remove; });
}

size_t Register::size() {
    return buffer.size();
}

void Register::update(const Message &msg) {
    std::cout<<"New Message from "<<msg.getSender().toString()<<std::endl;
}


std::string Register::toString() {
    std::string dump;
    dump += " DATABASE \n\n";
    for(auto obj : buffer){
        dump += obj.toString();
    }
    return dump;
}

Register::~Register() {
    for (auto &obj : buffer) {
        obj.detachObserver(*this);
    }
}