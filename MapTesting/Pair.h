#pragma once
#include <iostream>
using namespace std;

class Pair
{
	int key;
	int value;
public:
	Pair(int a, int b);
	Pair();
	void setPair(int a, int b);
	void setValue(int v);
	int getKey() const;
	int getValue() const;
	bool operator == (const Pair & p);
};

