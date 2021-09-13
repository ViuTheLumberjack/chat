//
// Created by シルブー on 13/09/2021.
//

#ifndef CHAT_OBSERVER_H
#define CHAT_OBSERVER_H


class Observer {
public:
    virtual void update(const Message &msg) = 0;
    virtual ~Observer() = 0;
};


#endif //CHAT_OBSERVER_H
