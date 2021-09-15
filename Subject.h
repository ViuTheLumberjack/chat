//
// Created by シルブー on 13/09/2021.
//

#ifndef CHAT_SUBJECT_H
#define CHAT_SUBJECT_H

#include <memory>
#include "Observer.h"

class Subject{
public:
    virtual void notifyObservers(const Message &msg) = 0;
    virtual void attachObserver(const std::shared_ptr<Observer> o) = 0;
    virtual void detachObserver(const std::shared_ptr<Observer> o) = 0;

protected:
    std::list<std::shared_ptr<Observer>> obs;
};


#endif //CHAT_SUBJECT_H
