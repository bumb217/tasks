#include"Stack.h"
#include<gtest\gtest.h>


TEST(stack, DEF_CONSTR)
{
    Stack<int> someStack;
    
    ASSERT_EQ(nullptr, someStack.getSt());
    ASSERT_EQ(0, someStack.getSize());
    ASSERT_EQ(nullptr, someStack.getTop());
}

TEST(stack, COPY_EMPTY_CONSTR)
{
    Stack<int> copyMe;
    Stack<int> someStack(copyMe);
    
    ASSERT_EQ(nullptr, someStack.getSt());
    ASSERT_EQ(0, someStack.getSize());
    ASSERT_EQ(nullptr, someStack.getTop());
}

TEST(stack, PUSH)
{
    Stack<int> someStack;
    someStack.push(2);
    
    ASSERT_NE(nullptr, someStack.getSt());
    ASSERT_EQ(2, someStack.getTop()->data);
    ASSERT_EQ(1, someStack.getSize());
}

TEST(stack, COPY_N_EMPTY_CONSTR)
{
    Stack<int> copyMe;
    copyMe.push(2);
    copyMe.push(54);
    Stack<int> someStack(copyMe);
    
    ASSERT_NE(nullptr, someStack.getSt());
    ASSERT_EQ(2, someStack.getSize());
    ASSERT_EQ(54, someStack.getTop()->data);
}

TEST(stack, IS_EMPTY)
{
    Stack<int> st;
    ASSERT_EQ(true, st.empty());
    st.push(3);
    ASSERT_EQ(false, st.empty());
}

TEST(stack, POP)
{
    Stack<int> s;
    s.push(2);
    s.push(5);
    int a = s.pop();
    ASSERT_EQ(5, a);
    int b = s.pop();
    ASSERT_EQ(2, b);
}

TEST(stack, POP_THROW)
{
    Stack<int> s;
    try {
        int a = s.pop();
        FAIL() << "Expected std::length_error";
    }
    catch (std::length_error const& err) {
        EXPECT_EQ(err.what(), std::string("Stack is empty"));
    };
}
