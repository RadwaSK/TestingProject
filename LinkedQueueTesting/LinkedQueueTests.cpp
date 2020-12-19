#include "pch.h"
#include "LinkedQueue.h"

TEST(QUEUE, CONSTRUCTOR_AND_IsEmpty) {
	LinkedQueue q = LinkedQueue();
	EXPECT_TRUE(q.isEmpty());
}

TEST(QUEUE, ENQUEUE_AND_PEEK_FRONT) {
	LinkedQueue q = LinkedQueue();
	q.enqueue(1);
	EXPECT_EQ(q.peekFront(), 1);
	q.enqueue(3);
	EXPECT_EQ(q.peekFront(), 1);
}

TEST(QUEUE, DEQUEUE) {
	LinkedQueue q = LinkedQueue();
	EXPECT_TRUE(q.isEmpty());
	q.enqueue(1);
	q.enqueue(3);
	EXPECT_TRUE(q.dequeue()); // bec. not empty
	EXPECT_FALSE(q.isEmpty());
	EXPECT_EQ(q.peekFront(), 3);
	q.dequeue();
	EXPECT_TRUE(q.isEmpty());
	EXPECT_FALSE(q.dequeue()); // bec. empty
}

TEST(QUEUE, COPY_CONSTRUCTOR) {
	LinkedQueue q = LinkedQueue();
	q.enqueue(3);
	q.enqueue(2);
	q.enqueue(1);
	LinkedQueue s2 = LinkedQueue(q);
	EXPECT_EQ(s2.peekFront(), 3);
	EXPECT_EQ(s2.peekFront(), 3);
}