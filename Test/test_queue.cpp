#include "gtest.h"
#include"../Queue/Queue.h"
TEST(TQueue, can_create_queue)
{
    ASSERT_NO_THROW(TQueue<int> q(20));
}
TEST(TQueue, cant_create_queue_with_negative_datacount)
{
    ASSERT_ANY_THROW(TQueue<int> q(-20));
}
TEST(TQueue, can_get_datacount)
{
    TQueue<int> q(20);
    q.Push(20);
    ASSERT_NO_THROW(q.GetDataCount());
    EXPECT_EQ(1, q.GetDataCount());
}
TEST(TQueue, check_empty_with_empty_queue)
{
    TQueue<int> q(20);
    EXPECT_EQ(true, q.Empty());
}
TEST(TQueue, check_empty_with_not_empty_queue)
{
    TQueue<int> q(20);
    q.Push(2);
    EXPECT_EQ(false, q.Empty());
}
TEST(TQueue, check_full_with_full_queue)
{
    TQueue<int> q(2);
    q.Push(1);
    q.Push(2);
    EXPECT_EQ(true, q.Full());
}
TEST(TQueue, check_full_with_not_full_queue)
{
    TQueue<int> q(5);
    q.Push(2);
    EXPECT_EQ(false, q.Full());
}
TEST(TQueue, throws_when_push_queue_full)
{
    TQueue<int> q(2);
    q.Push(1);
    q.Push(2);
    ASSERT_ANY_THROW(q.Push(2));
}
TEST(TQueue, can_see_head)
{
    TQueue<int> q(5);
    q.Push(5);
    ASSERT_NO_THROW(q.SeeHead());
}
TEST(TQueue, cant_get_head_from_empty_queue)
{
    TQueue <int> q(20);
    ASSERT_ANY_THROW(q.GetHead());
}
TEST(TQueue, can_get_head)
{
    TQueue <int> q(20);
    q.Push(5);
    ASSERT_NO_THROW(q.GetHead());
}