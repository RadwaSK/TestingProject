#include "pch.h"

#include "LinkedSortedList.h"

//Private Function to copy a list by recurssion

Node* LinkedSortedList::copyChain( Node* origChainPtr, Node *& newTail){
	Node* copiedChainPtr;

	if (origChainPtr->getNextNode() == nullptr)
		newTail = origChainPtr;

	if (origChainPtr == nullptr)
		copiedChainPtr = nullptr ;

	else
	{
		// Build new chain from given one
		Node* copiedChainPtr = new Node(origChainPtr->getItem());
		copiedChainPtr->setNextNode(copyChain(origChainPtr->getNextNode(), newTail));
	} // end if

	return copiedChainPtr;
}

//Default Constructor

LinkedSortedList::LinkedSortedList(){
	head = tail = nullptr;
}

//Copy Constructor

LinkedSortedList::LinkedSortedList(const LinkedSortedList& aList){
	head = copyChain(aList.head, tail);
}


LinkedSortedList::~LinkedSortedList(){
	clear();
}

Node* LinkedSortedList::getNodeBefore( const int& anEntry) const
{
	Node* curPtr = head;
	Node* prevPtr = nullptr;
	//The highest priority is at head, and least at tail
	while ( (curPtr != nullptr) && (anEntry < curPtr->getItem()) )
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNextNode();
	} // end while
	return prevPtr;
}

/////////////////////////////////////////////////////////////////////
//Main Operations
////////////////////////////////////////////////////////////////////


void LinkedSortedList::insertSorted( const int& newEntry){
	Node* newNodePtr = new Node(newEntry);

	Node* prevPtr = getNodeBefore(newEntry);

	if (isEmpty() || (prevPtr == nullptr )) // Add at beginning
	{
		newNodePtr->setNextNode(head);
		head = tail = newNodePtr;
	}
	else // Add after node before
	{
		Node* aftPtr = prevPtr->getNextNode();
		newNodePtr->setNextNode(aftPtr);

		if (aftPtr == nullptr) //if added in end
			tail = newNodePtr;

		prevPtr->setNextNode(newNodePtr);
	} // end if
}

//////////////////////////////////////////////////////////////////////////////////////
//Common Functions with Linked List
/////////////////////////////////////////////////////////////////////////////////////

//Check if empty

bool LinkedSortedList::isEmpty() const {
	if (head == nullptr)
		return true;
	return false;
}

//getItem that points to target T

Node* LinkedSortedList::getPrevPointer(const int & target) const {
	Node *prev = nullptr;

	//if empty
	if (isEmpty())
		return nullptr;

	Node* currentPtr = head;

	while (currentPtr != nullptr){
		if (currentPtr->getItem() == target)
			return prev;

		prev = currentPtr;
		currentPtr = currentPtr->getNextNode();
	}

	return nullptr;
}

//remove an T

bool LinkedSortedList::remove(const int & ItemToRemove){

	if (isEmpty()) return false;

	Node * prev = getPrevPointer(ItemToRemove);

	if (prev == nullptr){
		//if not found
		if (head->getItem() != ItemToRemove)
			return false;
		else { //first node is the element to be removed
			Node * nodeToDelete = head;
			if (tail == head)
				tail = tail->getNextNode(); //i.e. nullptr
			head = head->getNextNode();
			delete nodeToDelete;
			return true;
		}
	}

	if (prev->getNextNode() == tail){
		delete tail;
		tail = prev;
		tail->setNextNode(nullptr);
		return true;
	}

	Node * ptr = prev->getNextNode();
	prev->setNextNode(ptr->getNextNode());
	delete ptr;
	ptr = nullptr;
	return true;
}

//clear list and delete all entries

void LinkedSortedList::clear(){
	Node* nodeToDeletePtr;

	while (head != nullptr)
	{
		nodeToDeletePtr = head;
		head = head->getNextNode();

		// Return node to the system
		nodeToDeletePtr->setNextNode(nullptr);
		delete nodeToDeletePtr;
	} // end while

	// headPtr is nullptr
	nodeToDeletePtr = head = nullptr ;
	tail = nullptr;
}


int LinkedSortedList::getEntry(int position){
	int count = 0;
	Node * currPtr = head;
	while (count != position && currPtr){
		currPtr = currPtr->getNextNode();
		count++;
	}
	return currPtr->getItem();
}
