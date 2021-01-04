#include "pch.h"
#include "LinkedList.h"

TEST(ConstructorTest, EmptyConstructor) {
	LinkedList l = LinkedList();
  EXPECT_TRUE(l.isEmpty());
}
TEST(CopyConstructorTest, CopyConstructor) {
	LinkedList l = LinkedList();
	l.add(2);
	l.add(1);
	LinkedList l2 = LinkedList(l);
	EXPECT_TRUE(l2.contains(2));
	EXPECT_FALSE(l2.contains(6));
}
TEST(LinkedListTest, Add) {
	LinkedList l = LinkedList();
	bool tes = l.add(3);
	EXPECT_TRUE(tes);
	EXPECT_TRUE(l.contains(3));
	EXPECT_EQ(l.head->getItem(), l.tail->getItem());
	EXPECT_EQ(l.head->getItem(), 3);
	EXPECT_FALSE(l.isEmpty());
	tes = l.add(6);
	EXPECT_TRUE(tes);
	EXPECT_TRUE(l.contains(3));
	EXPECT_TRUE(l.contains(6));

	EXPECT_NE(l.head->getItem(), l.tail->getItem());
	EXPECT_EQ(l.head->getItem(), 3);
	EXPECT_EQ(l.tail->getItem(), 6);
}
TEST(LinkedListTest,Remove) {
	LinkedList l = LinkedList();
	bool tes = l.remove(3);
	EXPECT_FALSE(tes);
	l.add(4);
	tes = l.remove(3);
	EXPECT_FALSE(tes);
	l.add(3);
	tes = l.remove(3);
	EXPECT_TRUE(tes);
	EXPECT_EQ(l.head->getItem(), 4);
	EXPECT_EQ(l.head->getItem(), l.tail->getItem());
}

TEST(LinkedListTest, Clear) {
	LinkedList l = LinkedList();
	l.clear();
	EXPECT_EQ(l.head, nullptr);
	l.add(3);
	l.add(4);
	EXPECT_TRUE(l.contains(3));
	
	l.clear();
	EXPECT_EQ(l.head, nullptr);
	
}






