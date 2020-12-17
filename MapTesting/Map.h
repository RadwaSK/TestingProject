#pragma once
#include "Pair.h"

#define MAXSIZE 100

class Map
{
	Pair pairs[MAXSIZE];
	int count;
public:
	Map();
	bool addPair(const Pair &p);
	int getValue(const int &key) const;
	int getCount() const;
	bool UpdateValue(const int &key, const int&value);
	void displayMap() const;
	bool deletePair(const Pair &p);
};

