//
// Created by シルブー on 08/09/2021.
//

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

    Chat c1 { "Giulio", "Alberto"};
    Chat c2 { "Giulio", "Franco"};
    Register r;
};

TEST_F(RegisterTest, StandardFunctionalities){
    size_t n = r.size();
    ASSERT_EQ(n, 2);
}


TEST_F(RegisterTest, Remove){
    r.removeChat(c2);
    size_t n = r.size();
    ASSERT_EQ(n, 1);

    r.removeChat(c2);
    n = r.size();
    ASSERT_EQ(n, 1);
}
