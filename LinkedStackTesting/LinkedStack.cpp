#include "pch.h"
#include "LinkedStack.h"


LinkedStack::LinkedStack(){
	top = nullptr;
}


LinkedStack::LinkedStack(LinkedStack & aStack){ // Copy constructor
	top = nullptr;
	
	if (aStack.isEmpty())
		top = nullptr; // Original bag is empty
	else
	{
		LinkedStack temp;
		while (!aStack.isEmpty()) {
			temp.push(aStack.peek());
			aStack.pop();
		}

		while (!temp.isEmpty()) {
			int t = temp.peek();
			aStack.push(t);
			push(t);
			temp.pop();
		}
	}
}


LinkedStack::~LinkedStack(){ // Destructor
	while (!isEmpty())
		pop();
}


bool LinkedStack::isEmpty() const {
	return top == nullptr;
}



void LinkedStack::push( const int & newEntry ){
	if (isEmpty()) {
		top = new Node(newEntry);
	}
	else {
		Node * newNode = new Node(newEntry);
		newNode->setNextNode(top);
		top = newNode;
	}
	
}



bool LinkedStack::pop(){
	if (isEmpty()) return false;

	Node * nodeToPop = top;
	top = top->getNextNode();

	delete nodeToPop;

	return true;
}


int LinkedStack::peek() const {
	if (isEmpty())
		return NULL;
	return top->getItem();
}

