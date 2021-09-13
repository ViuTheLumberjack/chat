//
// Created by シルブー on 13/09/2021.
//

#ifndef CHAT_OBSERVER_H
#define CHAT_OBSERVER_H


class Observer {
public:
    virtual bool operator==(const Observer &rhs) { return typeid(*this) != typeid(rhs); };
    virtual void update(const Message &msg) {};
    virtual ~Observer() = default;
};


#endif //CHAT_OBSERVER_H
