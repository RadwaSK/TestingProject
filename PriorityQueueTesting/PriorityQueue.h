#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE
#include "LinkedSortedList.h"

class PriorityQueue
{

	LinkedSortedList* slistPtr; // Pointer to sorted list of
	// items in the priority queue

public :
	PriorityQueue();
	PriorityQueue(const PriorityQueue & pq);
	~PriorityQueue();

	bool isEmpty() const ;

	bool add( const int& newEntry);

	bool remove(int & removedItem);

	int peek();

}; // end SL_PriorityQueue

#endif