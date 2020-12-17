#pragma once

class Node
{
	int item;
	Node * next;
public:
	Node();
	Node(const int & newItem);
	Node(const int& newItem, Node *nextNodePtr);
	void setItem(const int & newItem);
	void setNextNode(Node *nextNodePtr);
	int getItem() const ;
	Node * getNextNode() const ;
};
