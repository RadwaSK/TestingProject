#include "pch.h"
#include "Map.h"
using namespace std;


Map::Map(){
	count = 0;
}


bool Map::addPair(int key, int value){
	if (count == MAXSIZE) return false;
	Pair p = Pair(key, value);
	pairs[count] = p;
	count++;
	return true;
}


int Map::getValue(int key) const {
	for (int i = 0; i<count; i++)
		if (pairs[i].getKey() == key)
			return pairs[i].getValue();
	return NULL;
}


int Map::getCount() const {
	return count;
}


bool Map::UpdateValue(const int &key, const int&value){
	for (int i = 0; i<count; i++)
		if (pairs[i].getKey() == key){
			pairs[i].setValue(value);
			return true;
		}
	return false;
}


bool Map::deleteKey(int key){

	for (int i = 0; i<count; i++)
		if (pairs[i].getKey() == key){
			for (int j = i; j<count-1; j++)
				pairs[j] = pairs[j+1];
			count--;
			return true;
		}

	return false;
}
