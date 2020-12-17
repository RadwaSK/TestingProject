#include "pch.h"
#include "List.h"


List::List(){
	size = MAXSIZE;
	nameOfList = "";
	for (int i = 0; i < MAXSIZE; i++)
		list[i] = 0;
}

List::List(int maxSize, char * name)
{
	size = maxSize;
	nameOfList = name;
	for (int i = 0; i < size; i++)
		list[i] = 0;
}


bool List::set(int index, const int &d){
	if (index >= size || index < 0) return false;
	list[index] = d;
	return true;
}

void List::setName(char * name)
{
	nameOfList = name;
}


int List::getIndex(const int &d) const {
	int i, j;

	for (i=0, j=size-1; i<size/2; i++, j--)
		if (list[i] == d) return i;
		else if (list[j] == d) return j;

	if (list[size / 2] == d) return size / 2;
	return -1;
}


void List::sort() { //Bubble Sort
	int temp;
	bool NoMoves = false;
	int counter = size-1;

	while (!NoMoves){
		NoMoves = true;

		for (int i = 0; i<counter; i++)
			if (list[i] > list[i+1]){
				temp = list[i];
				list[i] = list[i+1];
				list[i+1] = temp;
				NoMoves = false;
			}

		counter--;
	}

}


int List::getSize() const {
	return size;
}

char * List::getName() const
{
	return nameOfList;
}


int& List::operator [](int index) {
	return list[index];
}


List& List::operator = (List l){
	size = l.getSize();
	nameOfList = l.getName();
	for (int i = 0; i<size; i++)
		list[i] = l[i];
	return *this;
}


bool List::operator == (List l) const {
	for (int i = 0; i<size; i++)
		if (list[i] != l[i])
			return false;
	return true;
}

