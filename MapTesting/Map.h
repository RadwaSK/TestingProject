#pragma once
#include "Pair.h"

#define MAXSIZE 100

class Map
{
	Pair pairs[MAXSIZE];
	int count;
public:
	Map();
	bool addPair(int key, int value);
	int getValue(int key) const;
	int getCount() const;
	bool UpdateValue(const int &key, const int&value);
	bool deleteKey(int key);
};

