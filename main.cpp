#include <iostream>
#include "Register.h"

int main() {
    Register r;

    User u1 {"Marco"};
    User u2 {"Franco"};
    User u3 {"Mario"};

    Chat c1 {std::make_pair(u1, u2)};
    Chat c2 {std::make_pair(u1, u3)};

    c1.addMessage({"Yahallo!", u1});
    c1.addMessage({"Ciaooo", u2});
    c1.addMessage({"Ciaone", u3});

    r.addChat(c1);
    r.addChat(c2);

    std::cout << r.toString() << std::endl;

    return 0;
}
