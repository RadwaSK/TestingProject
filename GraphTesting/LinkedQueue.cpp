#include "pch.h"
#include "LinkedQueue.h"


LinkedQueue::LinkedQueue(){
	frontPtr = nullptr;
	backPtr = nullptr;
}


LinkedQueue::LinkedQueue( LinkedQueue & aQueue){
	frontPtr = backPtr = nullptr;
	LinkedQueue temp = LinkedQueue();

	while (!aQueue.isEmpty()) {
		temp.enqueue(aQueue.peekFront());
		aQueue.dequeue();
	}

	while (!temp.isEmpty()) {
		int t = temp.peekFront();
		temp.dequeue();
		enqueue(t);
		aQueue.enqueue(t);
	}
}


LinkedQueue::~LinkedQueue(){
	while (!isEmpty())
		dequeue();
}


bool LinkedQueue::isEmpty() const {
	if (frontPtr ==  nullptr && backPtr == nullptr) return true;
	return false;
}


bool LinkedQueue::enqueue(int newEntry){

	if (isEmpty()){
		frontPtr = new Node (newEntry);
		backPtr = frontPtr;
	}

	else {
		Node * newNode = new Node (newEntry);
		backPtr->setNextNode(newNode);
		backPtr = newNode;
	}

	return true;
}


bool LinkedQueue::dequeue(){
	if (isEmpty()) return false;
	
	int PopedEntry = frontPtr->getItem();

	//1 Node only in queue
	if (frontPtr == backPtr){
		delete frontPtr;
		frontPtr = backPtr = nullptr;
		return true;
	}

	Node * NodeToDelete = frontPtr;

	//shift frontPtr to the next element
	frontPtr = frontPtr->getNextNode();

	delete NodeToDelete;
	NodeToDelete = nullptr;

	return true;

}


int LinkedQueue::peekFront() const {
	assert(!isEmpty());
	return frontPtr->getItem();
}
