#include "pch.h"
#include "PriorityQueue.h"

//Default constructor

PriorityQueue::PriorityQueue(){
	slistPtr = new LinkedSortedList;
}

//Copy Constructor

PriorityQueue::PriorityQueue( const PriorityQueue & pq ) {
	slistPtr = new LinkedSortedList(*pq.slistPtr);
}

//Destructor

PriorityQueue::~PriorityQueue(){
	delete slistPtr;
}

//Check if sortedLinkedList is empty

bool PriorityQueue::isEmpty() const {
	return slistPtr->isEmpty();
}

//add item in sorted list

bool PriorityQueue::add( const int& newEntry){
	slistPtr->insertSorted(newEntry);
	return true;
}

//remove element of highest priority

bool PriorityQueue::remove(int & removedItem){
	if (isEmpty()) return false;

	removedItem = slistPtr->getEntry(0);
	return slistPtr->remove(removedItem);
}


int PriorityQueue::peek(){
	return slistPtr->getEntry(0);
}
