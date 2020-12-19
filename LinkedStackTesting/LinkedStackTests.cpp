#include "pch.h"
#include "LinkedStack.h"

TEST(STACK, CONSTRUCTOR_AND_IsEmpty) {
	LinkedStack s = LinkedStack();
	EXPECT_TRUE(s.isEmpty());
}

TEST(STACK, PUSH_AND_PEEK) {
	LinkedStack s = LinkedStack();
	s.push(1);
	EXPECT_EQ(s.peek(), 1);
	s.push(3);
	EXPECT_EQ(s.peek(), 3);
}

TEST(STACK, POP) {
	LinkedStack s = LinkedStack();
	s.push(1);
	s.push(3);
	EXPECT_TRUE(s.pop()); // bec. not empty
	EXPECT_FALSE(s.isEmpty());
	EXPECT_EQ(s.peek(), 1);
	s.pop();
	EXPECT_TRUE(s.isEmpty());
	EXPECT_FALSE(s.pop()); // bec. empty
}

TEST(STACK, COPY_CONSTRUCTOR) {
	LinkedStack s = LinkedStack();
	s.push(1);
	LinkedStack s2 = LinkedStack(s);
	EXPECT_EQ(s2.peek(), 1);
	EXPECT_EQ(s.peek(), 1); // to make sure it didn't change
}