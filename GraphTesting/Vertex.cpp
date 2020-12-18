#include "pch.h"
#include "Vertex.h"

//-------------Constructors-------------//

Vertex::Vertex(int d){
	data = d;
	nextVertex = nullptr; firstEdge = nullptr;
	inDegree = outDegree = processed = 0;
}
//-------------Setters-------------//

void Vertex::setData(int d){
	data = d;
}


void Vertex::setNextVertex(Vertex * v){
	nextVertex = v;
}


void Vertex::setFirstEdge(Edge * Edge){
	if (firstEdge == nullptr){
		inDegree++; outDegree++;
	}
	firstEdge = Edge;
}

//-------------Getters-------------//

int Vertex::getData() const {
	return data;
}


Vertex * Vertex::getNextVertex() const {
	return nextVertex;
}


Edge * Vertex::getFirstEdge() const {
	return firstEdge;
}


int Vertex::getProcessedCount() const {
	return processed;
}

//-------------Functions-------------//

void Vertex::incProcessed(){
	processed++;
}


void Vertex::resetProcessed(){
	processed = 0;
}


bool Vertex::isConnected(int v2) const {
	//if has no edges
	if (!HasEdges()) return false;

	Edge * edgePtr = firstEdge;
	//while I still have edge from this vertex
	while(edgePtr){
		if (edgePtr->getDestination() == v2)
			return true;
		edgePtr = edgePtr->getNext();
	}

	return false;
}


void Vertex::addEdge(int v, int weight){
	inDegree++; outDegree++;

	//if there is no edges
	if (!HasEdges()){
		firstEdge = new Edge(v, weight);
		return;
	}
	
	Edge * edgePtr = firstEdge;
	//to reach pointer to last edge
	while (edgePtr->getNext())
		edgePtr = edgePtr->getNext();
	
	Edge * newEdge = new Edge(v, weight);
	edgePtr->setNext(newEdge);
}


void Vertex::removeEdge(int d){
	if (!HasEdges()) return;

	if (firstEdge->getDestination() == d){
		Edge * EdgeToDelete = firstEdge;
		firstEdge = firstEdge->getNext();
		delete EdgeToDelete;
		EdgeToDelete = nullptr;
		inDegree--; outDegree--;
		return;
	}

	Edge * edgePtr = firstEdge->getNext();
	Edge * PrevEdgePtr = firstEdge;

	while (edgePtr){
		if (edgePtr->getDestination() == d){
			PrevEdgePtr->setNext(edgePtr->getNext());
			delete edgePtr;
			inDegree--; outDegree--;
			return;
		}
	}

}


int Vertex::getEdgeWeight(int destination) const {
	if (!isConnected(destination)) return 0;

	Edge * edgePtr = firstEdge;

	while (edgePtr){
		if (edgePtr->getDestination() == destination)
			return edgePtr->getWeight();
		edgePtr = edgePtr->getNext();
	}

	return 0;
}


bool Vertex::HasEdges() const {
	return firstEdge;
}

//-------------Destructor-------------//

Vertex::~Vertex(){
	if (!HasEdges()) return;

	Edge * edgePtr = firstEdge;
	Edge * EdgeToDelete;

	while (edgePtr){
		EdgeToDelete = edgePtr;
		edgePtr = edgePtr->getNext();
		delete EdgeToDelete;
	}

	firstEdge = edgePtr = EdgeToDelete = nullptr;
}
