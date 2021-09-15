//
// Created by シルブー on 08/09/2021.
//

#include "gtest/gtest.h"
#include "../Chat.h"

class ChatTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        ASSERT_NO_THROW(c1.addMessage( {"Ciao", u1} ));
        ASSERT_NO_THROW(c1.addMessage( {"Ciao!", u2} ));
        ASSERT_THROW(c1.addMessage( {"Wela", u3} ), std::invalid_argument);
    }

    User u1 {"Älberto"};
    User u2 {"Marco"};
    User u3 {"Franco"};

    Chat c1 { std::make_pair(u1, u2)};
    Chat c2 { std::make_pair(u1, u3)};
};

TEST_F(ChatTest, Size){
    size_t n = c1.size();
    ASSERT_EQ(n, 2);
    n = c2.size();
    ASSERT_EQ(n, 0);
    c1.removeMessage({"Ciao", u1});
    n = c1.size();
    ASSERT_EQ(n, 1);
}

TEST_F(ChatTest, ReadMessage){
    int n = c1.countUnread();
    ASSERT_EQ(n, 2);
    c1.readAll();
    n = c1.countUnread();
    ASSERT_EQ(n, 0);
}
