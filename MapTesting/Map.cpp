#include "pch.h"
#include "Map.h"
using namespace std;


Map::Map(){
	count = 0;
}


bool Map::addPair(const Pair &p){
	if (count == MAXSIZE) return false;
	pairs[count] = p;
	count++;
	return true;
}


int Map::getValue(const int &key) const {
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


void Map::displayMap() const {
	cout << "===============================" << endl;
	cout << "			Map Display			" << endl;
	cout << "===============================" << endl;
	for (int i = 0; i < count; i++) {
		cout << "Key " << pairs[i].getKey() << " has value " << pairs[i].getValue() << endl;
	}
	cout << "===============================" << endl;
}


bool Map::deletePair(const Pair &p){

	for (int i = 0; i<count; i++)
		if (pairs[i] == p){
			for (int j = i; j<count-1; j++)
				pairs[j] = pairs[j+1];
			count--;
			return true;
		}

	return false;
}
