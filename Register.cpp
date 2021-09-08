//
// Created by シルブー on 07/09/2021.
//

#include "Register.h"
#include <algorithm>

void Register::addChat(const Chat &chat) {
    if(std::find(buffer.begin(), buffer.end(), chat) == buffer.end())
        buffer.push_back(chat);
}

void Register::removeChat(const Chat &chat) {
    buffer.remove_if([=](auto to_remove) { return chat == to_remove; });
}

size_t Register::size() {
    return buffer.size();
}

std::string Register::toString() {
    std::string dump;
    dump += " DATABASE \n\n";
    for(auto obj : buffer){
        dump += obj.toString();
    }
    return dump;
}
