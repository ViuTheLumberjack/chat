//
// Created by シルブー on 07/09/2021.
//

#include "Message.h"

Message::Message(const std::string &message, User &sender, bool read) : text(message), sender(sender),
                                                             timestamp(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())),
                                                             read(read) {}

std::string Message::toString() {
    return std::ctime(&timestamp) + sender.getUsername() + " says: " + text + "\n";
}

const std::string &Message::getMessage() const {
    return text;
}

User &Message::getSender() const {
    return sender;
}

time_t Message::getTimestamp() const {
    return timestamp;
}

bool Message::isRead() const {
    return read;
}

void Message::setRead(bool read) {
    Message::read = read;
}


bool Message::operator==(const Message &rhs) const {
    return text == rhs.text &&
           sender == rhs.sender &&
           timestamp == rhs.timestamp;
}

bool Message::operator!=(const Message &rhs) const {
    return !(rhs == *this);
}