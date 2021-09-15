//
// Created by シルブー on 08/09/2021.
//

#include <regex>
#include "gtest/gtest.h"
#include "../Register.h"

class RegisterTest : public ::testing::Test {
protected:

protected:
    virtual void SetUp() {
        r.addChat(c1);
        r.addChat(c2);
        r.addChat(c2);
    }

    User u1 {"Giulio"};
    User u2 {"Alberto"};
    User u3 {"Marco"};
    Chat c1 {{u1, u2}};
    Chat c2 {{u1, u3}};
    Register r;
};

TEST_F(RegisterTest, SizeTest){
    ASSERT_EQ(r.size(), 2);
}


TEST_F(RegisterTest, Remove){
    r.removeChat(c2);
    size_t n = r.size();
    ASSERT_EQ(n, 1);

    r.removeChat(c2);
    n = r.size();
    ASSERT_EQ(n, 1);
}

TEST_F(RegisterTest, Observer){
    c1.addMessage( {"Ciao", u1} );
    ASSERT_NE(0, c1.getObserverNum());
    ASSERT_TRUE(c1.testMock);
    c1.addMessage( { "Hi", u2});
    ASSERT_FALSE(c1.testMock);

    c2.addMessage({"Robot", u3});
    ASSERT_TRUE(c2.testMock);

    ASSERT_EQ(c1.getObserverNum(), 1);
    ASSERT_EQ(c2.getObserverNum(), 1);

}
