#include "pch.h"
#include "Map.h"

TEST(MAP, Constructor) {
	Map m = Map();
	EXPECT_EQ(m.getCount(), 0);
}