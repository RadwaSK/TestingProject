#include "pch.h"
#include "Graph.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

//-------------Utility functions-------------//

Vertex * & Graph::getVertexPtr(int v) const {
	//this function assumes we are sure the vertex with value "v" exists
	Vertex * vxPtr = headVertex;

	while (vxPtr){
		if (vxPtr->getData() == v)
			return vxPtr;
		vxPtr = vxPtr->getNextVertex();
	}
}


Vertex * Graph::getPrevVertex(int data) const {
	if (isEmpty()) return nullptr;

	if (headVertex->getData() == data)
		return nullptr;

	Vertex * ptr = headVertex;

	while (ptr->getNextVertex()){
		if (ptr->getNextVertex()->getData() == data)
			return ptr;
		ptr = ptr->getNextVertex();
	}

	return nullptr;
}

//----------------------------------------------------------------------------//

//-------------Constructors-------------//

Graph::Graph(){
	headVertex = tailVertex = nullptr;
	numEdges = 0;
	numVertices = 0;
}

//-----------Main Operations-----------//

bool Graph::add(int vertex1, int vertex2, int edgeWeight) {
	//If Graph is empty
	if (isEmpty()){
		//create two vertices
		Vertex * v1 = new Vertex(vertex1);
		Vertex * v2 = new Vertex(vertex2);
		//Add an edge from v1 to destination vertex2
		v1->addEdge(vertex2, edgeWeight);
		//general vertices in graphs
		v1->setNextVertex(v2);
		//Add an edge from v2 to destination vertex1
		v2->addEdge(vertex1, edgeWeight);
		//set head and tail
		headVertex = v1; tailVertex = v2;
		numEdges++; numVertices = 2;
		return true;
	}

	//if there is already both vertices and are connected, return false
	if (isConnected(vertex1, vertex2)) return false;

	//if both vertices exist but are not connected
	if (isExist(vertex1) && isExist(vertex2) && !isConnected(vertex1, vertex2)){
		Vertex * v = getVertexPtr(vertex1);
		v->addEdge(vertex2, edgeWeight);
		v = getVertexPtr(vertex2);
		v->addEdge(vertex1, edgeWeight);
		numEdges++;
		return true;
	}
	//if only vertex1 exist
	if (isExist(vertex1) && !isExist(vertex2)){
		Vertex * newVx = new Vertex(vertex2);
		newVx->addEdge(vertex1, edgeWeight);
		Vertex * v = getVertexPtr(vertex1);
		v->addEdge(vertex2, edgeWeight);
		tailVertex->setNextVertex(newVx);
		tailVertex = tailVertex->getNextVertex();
		numEdges++; numVertices++;
		return true;
	}

	//if only vertex2 exist
	if (!isExist(vertex1) && isExist(vertex2)){
		Vertex * newVx = new Vertex(vertex1);
		newVx->addEdge(vertex2, edgeWeight);
		Vertex * v = getVertexPtr(vertex2);
		v->addEdge(vertex1, edgeWeight);
		tailVertex->setNextVertex(newVx);
		tailVertex = tailVertex->getNextVertex();
		numEdges++; numVertices++;
		return true;
	}

	//if neither exists
	Vertex * v1 = new Vertex(vertex1);
	Vertex * v2 = new Vertex(vertex2);
	v1->addEdge(vertex2, edgeWeight);
	v2->addEdge(vertex1, edgeWeight);
	tailVertex->setNextVertex(v1);
	tailVertex = tailVertex->getNextVertex();
	tailVertex->setNextVertex(v2);
	tailVertex = tailVertex->getNextVertex();
	numEdges++; numVertices += 2;
	return true;
}


bool Graph::remove(int vertex1, int vertex2){
	if (isEmpty() || !isExist(vertex1) || !isExist(vertex2)) return false;
	//At this point I know I have at least two vertices

	Vertex * v1 = getVertexPtr(vertex1);
	Vertex * v2 = getVertexPtr(vertex2);

	//if two vertices are not connected
	if (!v1->isConnected(vertex2)) return false;
	//At this point I am sure they are connected

	//remove edge from both vertices
	v1->removeEdge(vertex2);
	v2->removeEdge(vertex1);
	
	//if v1 is not connected to any vertex
	if (!v1->HasEdges()){
		if (v1 == headVertex)
			headVertex = headVertex->getNextVertex();
		else if (v1 == tailVertex){
			//move tail one step backward (P.S. I know getPrevVertex won't return nullptr
			//because I know v1 != headVertex and that the vertex1 exists
			tailVertex = getPrevVertex(tailVertex->getData());
			tailVertex->setNextVertex(nullptr);
		}
		//else .. if just a vertes in between graph
		else {
			Vertex * prev = getPrevVertex(vertex1);
			prev->setNextVertex(v1->getNextVertex());
		}
		delete v1;
		v1 = nullptr;
		numVertices--;
	}

	//if v2 is not connected to any vertex
	if (!v2->HasEdges()){
		//if last vertex in Graph (surely same as v2)
		if (headVertex == tailVertex)
			headVertex = tailVertex = nullptr;
		//if v2 is headVertex
		else if (v2 == headVertex)
			headVertex = headVertex->getNextVertex();
		//if v2 is tailVertex
		else if (v2 == tailVertex){
			//move tail one step backward (P.S. I know getPrevVertex won't return nullptr
			//because I know v2 != headVertex and that the vertex2 exists
			tailVertex = getPrevVertex(tailVertex->getData());
			tailVertex->setNextVertex(nullptr);
		}
		//else .. if just a vertes in between graph
		else {
			Vertex * prev = getPrevVertex(vertex2);
			prev->setNextVertex(v2->getNextVertex());
		}
		delete v2;
		v2 = nullptr;
		numVertices--;
	}
	numEdges--;
	return true;
}


void Graph::clear() {
	if (isEmpty()) return;

	Vertex * vx = headVertex;
	Vertex * vxToDelete;

	while (vx){
		vxToDelete = vx;
		vx = vx->getNextVertex();
		delete vxToDelete;
	}

	vx = vxToDelete = headVertex = tailVertex = nullptr;
	numEdges = 0;
	numVertices = 0;
}


bool Graph::isExist(int vx) const {
	if (isEmpty()) return false;

	Vertex * startPtr = headVertex;
	//while I still have vertices in graph
	while (startPtr){
		if (startPtr->getData() == vx)
			return true;
		startPtr = startPtr->getNextVertex();
	}

	return false;
}


bool Graph::isEmpty() const {
	if (!headVertex) return true;
	return false;
}


bool  Graph::isConnected(int v1, int v2) const {
	//if graph is empty, or there's no v1, or there's no v2
	if (isEmpty() || !isExist(v1) || !isExist(v2)) return false;

	//get Ptr to the vertex having value v1 .. I am sure it exists now,
	//so no need to make sure it is not equal to nullptr
	Vertex * vx1 = getVertexPtr(v1);
	if (vx1->isConnected(v2)) return true;

	//This part is temporarily and should be removed as it will return same
	//result of the above condition, bec. if v1 is connected with v2,
	//then v2 is connected with v1 .. this is a non-directional graph
	Vertex * vx2 = getVertexPtr(v2);
	if (vx2->isConnected(v1)) return true;

	//if not connected
	return false;
}

//-------------Getters-------------//

int Graph::getNumVertices() const {
	return numVertices;
}


int Graph::getNumEdges() const {
	return numEdges;
}


int Graph::getEdgeWeight(int start, int end) const {
	if (!isExist(start) || !isExist(end)) return -1;

	//I made sure it exists, so no need to make sure it is not nullptr
	Vertex * v = getVertexPtr(start);
	if (!v->isConnected(end)) return -1;
	
	return v->getEdgeWeight(end);
}

//-------------Traversals-------------//

string Graph::depthFirstTraversal(int start){
	if (isEmpty() || !isExist(start)) return "";

	if (numVertices == 1){
		return to_string(start);
	}

	Vertex * vx = getVertexPtr(start);
	Edge * edge = vx->getFirstEdge();
	LinkedStack S;
	int value;
	
	//push 1st node
	S.push(start);
	vx->incProcessed();
	//Note: if proc. == 1, then it was pushed in stack,
	//if proc. == 0, then it wasn't pushed yet
	
	string res = "";

	while (!S.isEmpty()){
		//visit top
		value = S.peek();
		res += to_string(value);
		S.pop();

		//push edges to the current vertex
		while (edge){
			vx = getVertexPtr(edge->getDestination());
			if (vx->getProcessedCount() == 0){
				S.push(edge->getDestination());
				vx->incProcessed();
			}
			edge = edge->getNext();
		}
		//get vertex having value of stack top
		if(S.isEmpty()) break;

		vx = getVertexPtr(S.peek());
		edge = vx->getFirstEdge();
	}

	//reset processed counter
	vx = headVertex;
	while (vx){
		vx->resetProcessed();
		vx = vx->getNextVertex();
	}
	return res;
}


string Graph::breadthFirstTraversal(int start){
	if (isEmpty() || !isExist(start)) return "";

	if (numVertices == 1){
		return to_string(start);
	}

	Vertex * vx = getVertexPtr(start);
	Edge * edge = vx->getFirstEdge();
	LinkedQueue Q;
	int value;
	
	//push 1st node
	Q.enqueue(start);
	vx->incProcessed();
	//Note: if proc. == 1, then it was pushed in stack,
	//if proc. == 0, then it wasn't pushed yet
	
	string res = "";

	while (!Q.isEmpty()){
		//visit top
		value = Q.peekFront();
		res += to_string(value);
		Q.dequeue();

		//push edges to the current vertex
		while (edge){
			vx = getVertexPtr(edge->getDestination());
			if (vx->getProcessedCount() == 0){
				Q.enqueue(edge->getDestination());
				vx->incProcessed();
			}
			edge = edge->getNext();
		}
		//get vertex having value of stack top
		if(Q.isEmpty()) break;

		vx = getVertexPtr(Q.peekFront());
		edge = vx->getFirstEdge();
	}

	//reset processed counter
	vx = headVertex;
	while (vx){
		vx->resetProcessed();
		vx = vx->getNextVertex();
	}
	return res;
}