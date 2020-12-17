#include "pch.h"
#include "Pair.h"


Pair::Pair(int a, int b){
	key = a; value = b;
}

Pair::Pair()
{
}


void Pair::setPair(int a, int b){
	key = a; value = b;
}

void Pair::setValue(int v)
{
	value = v;
}


int Pair::getKey() const {
	return key;
}


int Pair::getValue() const {
	return value;
}


bool Pair::operator == (const Pair & p){
	return (key == p.key && value == p.value);
}
