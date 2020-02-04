//Copyright 2020 <boikov3>
#include <gtest/gtest.h>
#include "Stack1.h"
#include "Stack2.h"



const int a = 7;
const int b = 15;

TEST(stack1, first_push)
{
    Stack1 <int> stack;

    stack.push(a);
    stack.push(b);

    EXPECT_EQ(stack.head(), b);
}

TEST(stack1, pop)
{
    Stack1 <int> stack;

    stack.push(a);
    stack.push(b);

    stack.pop();

    EXPECT_EQ(stack.head(), a);
}

TEST(stack1, test_error_empty_stack_pop)
{
    Stack1 <int> stack;

    EXPECT_THROW(stack.pop(), std::logic_error);
}

TEST(stack1, test_error_empty_stack_head)
{
    Stack1 <double> stack;

    EXPECT_THROW(stack.head(), std::logic_error);
}

TEST(stack1, second_push)
{
    Stack1 <int> stack;

    stack.push(std::move(a));
    stack.push(std::move(b));

    EXPECT_EQ(stack.head(), b);

    stack.pop();

    EXPECT_EQ(stack.head(), a);
}



TEST(stack2, push_emplace)
{
    Stack2 < std::pair <int, double>> stack{};

    stack.push_emplace(15, 30.5);
    stack.push_emplace(7, 9.2);

    auto pair = std::make_pair(7, 9.2);
    EXPECT_EQ(stack.head(), pair);
}


TEST(stack2, pop)
{
    Stack2 < std::pair <int, double>> stack{};

    stack.push_emplace(67, 8.69);
    stack.push_emplace(3, 4.02);

    auto pair = std::make_pair(3, 4.02);
    EXPECT_EQ(stack.head(), pair);


    auto pair2 = std::make_pair(3, 4.02);
    EXPECT_EQ(stack.pop(), pair2);
}

TEST(stack2, push)
{
    Stack2 <double> stack;

    stack.push(2.1);
    stack.push(6.6);

    EXPECT_EQ(stack.head(), 6.6);
}

TEST(stack2, except)
{
    Stack2 <int> stack;

    EXPECT_THROW(stack.pop(), std::logic_error);
}

TEST(stack2, excepthead)
{
    Stack2 <int> stack;

    EXPECT_THROW(stack.head(), std::logic_error);
}


TEST(stak12, testcopy)
{
    EXPECT_EQ(std::is_copy_constructible_v<Stack1<int>>, false);
    EXPECT_EQ(std::is_copy_constructible_v<Stack2<int>>, false);

    EXPECT_EQ(std::is_copy_assignable_v<Stack1<int>>, false);
    EXPECT_EQ(std::is_copy_assignable_v<Stack2<int>>, false);
}

TEST(stak12, testmove)
{
    EXPECT_EQ(std::is_move_constructible_v<Stack1<int>>, true);
    EXPECT_EQ(std::is_move_constructible_v<Stack2<int>>, true);

    EXPECT_EQ(std::is_move_assignable_v<Stack1<int>>, true);
    EXPECT_EQ(std::is_move_assignable_v<Stack2<int>>, true);
}
