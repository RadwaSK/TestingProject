#include "pch.h"
#include "Edge.h"

//-------------Constructors-------------//


Edge::Edge(int d){
	destination = d;
	NextEdge = nullptr;
	weight = 0;
}


Edge::Edge(int d, long w){
	destination = d;
	NextEdge = nullptr;
	weight = w;
}


Edge::Edge(int d, Edge * nxtEdge){
	destination = d;
	NextEdge = nxtEdge;
	weight = 0;
}


Edge::Edge(int d, Edge * nxtEdge, long w){
	destination = d;
	NextEdge = nxtEdge;
	weight = w;
}

//-------------Setters-------------//


void Edge::setDestination(int d){
	destination = d;
}



void Edge::setNext(Edge * nxt){
	NextEdge = nxt;
}


void Edge::setWeight(long w) {
	weight = w;
}

//-------------Getters-------------//


int Edge::getDestination() const {
	return destination;
}


Edge * Edge::getNext() const {
	return NextEdge;
}

long Edge::getWeight() const {
	return weight;
}
