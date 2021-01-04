#include "pch.h"
#include "LinkedList.h"


//Default constructor

LinkedList::LinkedList() {
	head = tail = nullptr;
}

// Copy constructor

LinkedList::LinkedList(const LinkedList & aList) {
	if (aList.isEmpty()) {
		head = tail = nullptr;
		return;
	}

	head = new Node(aList.head->getItem());
	if (aList.head->getNextNode() == nullptr) {
		head->setNextNode(nullptr);
		tail = head;
		return;
	}

	Node* currPtr = head;
	Node* aListCurrPtr = aList.head->getNextNode();
	Node* newNode;
	while (aListCurrPtr != nullptr) {
		newNode = new Node(aListCurrPtr->getItem());
		currPtr->setNextNode(newNode);
		currPtr = newNode;
		aListCurrPtr = aListCurrPtr->getNextNode();
		tail = newNode;
	}
	tail->setNextNode(nullptr);
}

//Check if empty

bool LinkedList::isEmpty() const {
	if (head == nullptr)
		return true;
	return false;
}

//Add an item

bool LinkedList::add(const int & newEntry) {
	//means was empty
	if (isEmpty()) {
		Node* newNode = new Node(newEntry);
		head = tail = newNode;
		return true;
	}

	//else, add in end
	Node *newNode = new Node(newEntry);
	tail->setNextNode(newNode);
	tail = newNode;
	return true;
}

//remove an T

bool LinkedList::remove(const int& ItemToRemove) {

	if (isEmpty()) return false;

	Node * prev = getPrevPointer(ItemToRemove);

	if (prev == nullptr) {
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

	if (prev->getNextNode() == tail) {
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

void LinkedList::clear() {
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
	nodeToDeletePtr = head = nullptr;
	tail = nullptr;
}

//check if an T exists

bool LinkedList::contains(const int & Element) const {
	if (head->getItem() == Element) return true;
	return getPrevPointer(Element) != nullptr;
}

//getItem that points to target T

Node* LinkedList::getPrevPointer(const int & target) const {
	Node *prev = nullptr;

	//if empty
	if (isEmpty())
		return nullptr;

	Node* currentPtr = head;

	while (currentPtr != nullptr) {
		if (currentPtr->getItem() == target)
			return prev;

		prev = currentPtr;
		currentPtr = currentPtr->getNextNode();
	}

	return nullptr;
}

//Destructor

LinkedList::~LinkedList() {
	if (head == nullptr)
		return;

	if (head == tail) {
		delete head;
		head = tail = nullptr;
		return;
	}

	Node * nodeToDeletePtr;
	while (head != nullptr)
	{
		nodeToDeletePtr = head;
		head = head->getNextNode();

		// Return node to the system
		nodeToDeletePtr->setNextNode(nullptr);

		delete nodeToDeletePtr;
	}

	nodeToDeletePtr = tail = nullptr;

}
