#ifndef _EDGE
#define _EDGE

class Edge
{
	int destination;
	Edge * NextEdge;	//ptr to next Edge
	long weight;				//weight of Edge
public:
	//constructors
	Edge(int d);
	Edge(int d, long w);
	Edge(int d, Edge * nxtEdge);
	Edge(int d, Edge * nxtEdge, long w);
	//setters
	void setDestination(int d);
	void setNext(Edge * nxt);
	void setWeight(long w);
	//getters
	int getDestination() const ;
	Edge * getNext() const ;
	long getWeight() const ;
};

#endif