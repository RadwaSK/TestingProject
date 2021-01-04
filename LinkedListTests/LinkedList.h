#ifndef _LINKED_LIST
#define __LINKED_LIST
#include "Node.h"


class LinkedList
{
	

	// Returns the pointer whose next is the target, nullptr if not found

public:
	Node * head;
	Node * tail;
	LinkedList();

	LinkedList(const LinkedList & aList); // Copy constructor

	virtual ~LinkedList(); // Destructor should be virtual
	Node* getPrevPointer(const int & target) const;

	//check if it's empty
	bool isEmpty() const;

	//add a node
	bool add(const int & newEntry);

	//remove a node
	bool remove(const int & ItemToRemove);

	//delete all nodes
	void clear();

	//check if it contains an element
	bool contains(const int & Element) const;


};
#endif