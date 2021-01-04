#include "pch.h"
#include"PriorityQueue.h"
TEST(PriorityQueue, Constructor) {
	PriorityQueue q = PriorityQueue();
	EXPECT_TRUE(q.isEmpty());
	q.add(1);
	q.add(3);
	q.add(5);
	q.add(6);

	EXPECT_FALSE(q.isEmpty());

}
TEST(PriorityQueue, Add) {
	PriorityQueue q = PriorityQueue();
	EXPECT_TRUE(q.isEmpty());
	q.add(1);
	q.add(3);
	q.add(5);
	q.add(6);
	EXPECT_FALSE(q.isEmpty());
	EXPECT_EQ(q.peek(), 6);
  
}
TEST(PriorityQueue, Remove) {
	PriorityQueue q = PriorityQueue();
	EXPECT_TRUE(q.isEmpty());
	q.add(1);
	q.add(3);
	q.add(5);
	q.add(6);
	
	EXPECT_EQ(q.peek(), 6);
	int x = 6;
	q.remove(x);
	EXPECT_EQ(q.peek(), 5);


}

