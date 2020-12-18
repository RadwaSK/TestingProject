#ifndef _VERTEX
#define _VERTEX

#include "Edge.h"

class Vertex
{
	int data;
	Vertex * nextVertex;
	int inDegree, outDegree;
	Edge * firstEdge;
	int processed;
public:
	//constructors
	Vertex(int d);
	//setters
	void setData(int d);
	void setNextVertex(Vertex * v);
	void setFirstEdge( Edge * Edge );
	//getters
	int getData() const ;
	Vertex * getNextVertex() const ;
	Edge * getFirstEdge() const ;
	int getProcessedCount() const ;
	//another functions
	void incProcessed();
	void resetProcessed();
	bool isConnected(int v2) const ;
	void addEdge(int v, int weight);
	void removeEdge(int d);
	int getEdgeWeight(int destination) const ;
	bool HasEdges() const ;
	//destructor
	~Vertex();
};

#endif