#pragma once

#define MAXSIZE 50

class List
{
	int list[MAXSIZE];
	int size;
	char * nameOfList;
public:
	List();
	List(int maxSize, char * name);
	bool set(int index, const int &d);
	void setName(char * name);
	int getIndex(const int &d) const;
	void sort();
	int getSize() const;
	char * getName() const;
	int& operator [](int index);
	List& operator = (List l);
	bool operator == (List l) const ;
};

