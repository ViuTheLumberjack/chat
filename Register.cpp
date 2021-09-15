//
// Created by シルブー on 07/09/2021.
//

#include "Register.h"
#include <algorithm>
#include <iostream>

void Register::addChat(Chat &chat) {
    if(std::find(buffer.begin(), buffer.end(), chat) == buffer.end()){
        chat.attachObserver(std::make_shared<Register>(*this));
        buffer.emplace_back(chat);
    }
}

void Register::removeChat(Chat &chat) {
    buffer.remove_if([=](auto to_remove) {
        if (chat == to_remove) to_remove.detachObserver(std::make_shared<Register>(*this));
        return chat == to_remove;
    });
}


void Register::addMessage(const Message &msg, Chat &chat) {
    auto place = std::find(buffer.begin(), buffer.end(), chat);
    if(place != buffer.end()){
        place->addMessage(msg);
    }
}

size_t Register::size() const{
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
        dump += "-----------------\n\n";
    }
    return dump;
}
