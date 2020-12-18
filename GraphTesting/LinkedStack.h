#ifndef _LINKED_STACK
#define __LINKED_STACK

#include "Node.h"


class LinkedStack
{
	Node* top; // Index to top of stack
public:
	LinkedStack(); // Default constructor
	LinkedStack(LinkedStack &aStack); // Copy constructor
	~LinkedStack(); // Destructor

	bool isEmpty() const ;

	void push( const int & newEntry );

	bool pop();

	int peek() const ;

}; // end ArrayStack


#endif