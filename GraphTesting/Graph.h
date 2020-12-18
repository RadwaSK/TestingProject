#ifndef _GRAPH
#define _GRAPH

#include "Vertex.h"
#include <string>
using namespace std;

class Graph
{
	Vertex * headVertex;
	Vertex * tailVertex;
	int numVertices;
	int numEdges;
	//utility functions
	Vertex * & getVertexPtr(int v) const ;
	Vertex * getPrevVertex(int data) const ;
public:
	//constructors
	Graph();
	//main operations
	bool add(int vertex1, int vertex2, int edgeWeight) ;
	bool remove(int vertex1, int vertex2);
	void clear() ;
	bool isExist(int vertex) const ;
	bool isEmpty() const ;
	bool isConnected(int v1, int v2) const ;
	//getters
	int getNumVertices() const ;
	int getNumEdges() const ;
	int getEdgeWeight(int start, int end) const ;
	//Traversals
	string depthFirstTraversal(int start);
	string breadthFirstTraversal(int start);
};

#endif