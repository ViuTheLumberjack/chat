//
// Created by シルブー on 07/09/2021.
//

#ifndef CHAT_USER_H
#define CHAT_USER_H

#include <string>
#include <utility>

class User {
public:

    User(const std::string& username): username(username) {};

    bool operator==(const User &rhs) const {
        return username == rhs.username;
    }
    bool operator!=(const User &rhs) const {
        return !(rhs == *this);
    }

    const std::string &getUsername() const {
        return username;
    }
    void setUsername(const std::string &username) {
        User::username = username;
    }

    std::string toString(){
        return "User: " + username + "\n";
    }

private:
    std::string username;
    //other info
};


#endif //CHAT_USER_H
