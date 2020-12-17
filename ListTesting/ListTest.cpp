#include "pch.h"
#include "List.h"

TEST(LIST, EMPTY_CONSTRUCTOR) {
	List l = List();
	EXPECT_EQ(l.getSize(), MAXSIZE);
	EXPECT_STREQ(l.getName(), "");
	for (int i = 0; i < MAXSIZE; i++)
		EXPECT_EQ(l[i], 0);
}

TEST(LIST, INIT_CONSTRUCTOR) {
	List l = List(3, "smallList");
	EXPECT_EQ(l.getSize(), 3);
	EXPECT_STREQ(l.getName(), "smallList");
	for (int i = 0; i < 3; i++)
		EXPECT_EQ(l[i], 0);
}

TEST(LIST, CHANGE_NAME) {
	List l = List(3, "smallList");
	EXPECT_STREQ(l.getName(), "smallList");
	l.setName("newName");
	EXPECT_STREQ(l.getName(), "newName");
}

TEST(LIST, SET_VALUES) {
	List l = List(10, "myList");
	EXPECT_TRUE(l.set(4, 5));
	EXPECT_FALSE(l.set(-4, 20)); // negative index
	EXPECT_FALSE(l.set(13, 5)); // over capacity
}

TEST(LIST, OPERATOR_OVERLOADING) {
	List l = List(20, "operatorOverloaded");
	l[3] = 30;
	EXPECT_EQ(l[3], 30);
	EXPECT_TRUE(l[3] == 30);
}

TEST(LIST, EQUAL_LIST) {
	List l = List(6, "testList");
	List l1 = List(4, "list1");
	List l2 = List(7, "list2");

	for (int i = 0; i < 4; i++)
		l1[i] = i;

	for (int i = 0; i < 7; i++)
		l2[i] = 10 * i;

	l = l1;
	EXPECT_EQ(l.getSize(), 4);
	EXPECT_STREQ(l.getName(), "list1");
	EXPECT_EQ(l[0], 0);
	EXPECT_EQ(l[2], 2);
	EXPECT_EQ(l[3], 3);

	l = l2;
	EXPECT_EQ(l.getSize(), 7);
	EXPECT_STREQ(l.getName(), "list2");
	EXPECT_EQ(l[0], 0);
	EXPECT_EQ(l[3], 30);
	EXPECT_EQ(l[6], 60);
}

TEST(LIST, SORT) {
	List l = List(5, "unsortedList");
	l[0] = 4;
	l[1] = 2;
	l[2] = 0;
	l[3] = -4;
	l[4] = 1;

	l.sort();
	EXPECT_EQ(l[0], -4);
	EXPECT_EQ(l[1], 0);
	EXPECT_EQ(l[2], 1);
	EXPECT_EQ(l[3], 2);
	EXPECT_EQ(l[4], 4);
}

TEST(LIST, GET_INDEX) {
	List l = List(9, "testList");
	
	for (int i = 0; i < 9; i++)
		l[i] = i * 10;
	
	EXPECT_EQ(l.getIndex(30), 3);
	EXPECT_EQ(l.getIndex(0), 0);
	EXPECT_EQ(l.getIndex(40), 4);
	EXPECT_EQ(l.getIndex(80), 8);
	EXPECT_EQ(l.getIndex(18), -1);
}