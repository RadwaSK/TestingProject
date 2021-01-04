#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "Node.h"

//The highest priority is at head, and least at tail

class LinkedSortedList
{
	Node* head; // Pointer to first node in the chain
	Node * tail; //Pointer to last node in chain


	// Locates the node that is before the node that should or does contain the given entry.
	Node* getNodeBefore(const int & anEntry) const ;

	// Returns a pointer to a copy of the chain to which origChainPtr points.
	Node* copyChain( Node* origChainPtr, Node *& newTail);

	// Returns the pointer whose next is the target, nullptr if not found
	Node* getPrevPointer(const int & target) const ;
public :
	LinkedSortedList();
	LinkedSortedList(const LinkedSortedList& aList);
	~LinkedSortedList();

	void insertSorted( const int& newEntry);

	////////////////////////////////////////////////////////////////
	// The following methods are the same as given in ListInterface:
	///////////////////////////////////////////////////////////////

	//check if it's empty
	bool isEmpty() const ;

	//remove a node
	bool remove(const int & anEntry);

	//delete all nodes
	void clear();

	//get an Entry from the list
	int getEntry(int position);

}; // end LinkedSortedList

#endif