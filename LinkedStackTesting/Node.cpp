#include "pch.h"
#include "Node.h"


Node::Node(){
	next = nullptr;
}


Node::Node(const int & newItem){
	item = newItem;
	next = nullptr;
}


Node::Node(const int & newItem, Node *nextNodePtr){
	item = newItem;
	next = nextNodePtr;
}


void Node::setItem(const int & newItem){
	item = newItem;
}


void Node::setNextNode(Node *nextNodePtr){
	next = nextNodePtr;
}


int Node::getItem() const {
	return item;
}


Node * Node::getNextNode() const {
	return next;
}
