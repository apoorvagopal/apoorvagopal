#include "pch.h"

/*class queuefix : public ::testing::Test
{
public:
    Queue<int> queue;
};*/

TEST(queuefix, EnqueueOnEmptyQueue) {
    Queue<int> queue;
    ASSERT_EQ(queue.GetSize(), 0);
    std::cout << "assert execution";
    queue.Enqueue(10);
    EXPECT_EQ(queue.GetSize(), 1);
    EXPECT_EQ(queue.Peek(), 10);
}

/*TEST(queuefixchar, EnqueueOnEmptyQueue) {
    Queue<char> queue;
    ASSERT_EQ(queue.GetSize(), 0);
    std::cout<<"assert execution";
    queue.Enqueue('A');
    EXPECT_EQ(queue.GetSize(), 1);
    EXPECT_EQ(queue.Peek(),'A');
}*/

TEST(queuefix, EnqueueMultipleElements) {
    Queue<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    EXPECT_EQ(queue.GetSize(), 4);
    EXPECT_EQ(queue.Peek(), 10);
}

TEST(DeQueueTest, DequeueElement) {
    Queue<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);

    queue.Dequeue();
    EXPECT_EQ(queue.GetSize(), 3);
    EXPECT_EQ(queue.Peek(), 20);
}

TEST(QueueTest, PeekFrontElement) {
    Queue<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);

    EXPECT_EQ(queue.Peek(), 10);
}

TEST(QueueTest, GetSize) {
    Queue<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);

    EXPECT_EQ(queue.GetSize(), 4);
}

TEST(DeQueueTest, DequeueAllElements) {
    Queue<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);

    while (!queue.IsEmpty()) {
        queue.Dequeue();
    }

    ASSERT_TRUE(queue.IsEmpty());
    ASSERT_EQ(queue.GetSize(), 0);

    /* EXPECT_EQ(queue.GetSize(), 0);
     EXPECT_THROW(queue.Peek(), std::runtime_error);
     EXPECT_NO_THROW(queue.Dequeue());*/
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
