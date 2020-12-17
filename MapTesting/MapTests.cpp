#include "pch.h"
#include "Map.h"

TEST(MAP, CONSTRUCTOR_AND_GET_COUNT) {
	Map m = Map();
	EXPECT_EQ(m.getCount(), 0);
}

TEST(MAP, ADD_AND_GET_Pair) {
	Map m = Map();
	EXPECT_TRUE(m.addPair(1, -4));
	EXPECT_EQ(m.getCount(), 1);
	EXPECT_EQ(m.getValue(1), -4); // return value if key exist
	EXPECT_EQ(m.getValue(2), NULL); // return NULL if not exist
	EXPECT_TRUE(m.addPair(1.4, 0));
	// if key is float, it should be floored
	EXPECT_EQ(m.getValue(1.4), -4); // same as key: 1
}

TEST(MAP, MAX_CAPACITY) {
	Map m = Map();
	for (int i = 0; i < MAXSIZE; i++)
		EXPECT_TRUE(m.addPair(i, i));
	
	EXPECT_EQ(m.getCount(), 100);
	EXPECT_FALSE(m.addPair(100, 100));
	EXPECT_EQ(m.getCount(), 100);
}

TEST(MAP, UPDATE_VALUE) {
	Map m = Map();
	EXPECT_TRUE(m.addPair(5, 30));
	EXPECT_EQ(m.getValue(5), 30); 
	EXPECT_TRUE(m.UpdateValue(5, 50)); //updating done successfully
	EXPECT_EQ(m.getValue(5), 50); // m[5] should equal 50 now
	EXPECT_FALSE(m.UpdateValue(3, 4)); // key 3 doesn't exist
}

TEST(MAP, DELETE_Key) {
	Map m = Map();
	EXPECT_TRUE(m.addPair(3, 30));
	EXPECT_TRUE(m.addPair(5, 50));
	EXPECT_EQ(m.getCount(), 2);
	EXPECT_TRUE(m.deleteKey(3));
	EXPECT_EQ(m.getCount(), 1);
	EXPECT_FALSE(m.deleteKey(7));
	EXPECT_EQ(m.getCount(), 1);
}