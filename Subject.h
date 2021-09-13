//
// Created by シルブー on 13/09/2021.
//

#ifndef CHAT_SUBJECT_H
#define CHAT_SUBJECT_H

#include "Observer.h"

class Subject{
public:
    virtual void notifyObservers(const Message &msg) = 0;
    virtual void attachObserver(const Observer &o) = 0;
    virtual void detachObserver(const Observer &o) = 0;
    virtual ~Subject() = 0;

protected:
    std::list<Observer&> obs;
};


#endif //CHAT_SUBJECT_H
