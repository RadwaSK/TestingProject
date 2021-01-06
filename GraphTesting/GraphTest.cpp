#include "pch.h"
#include "Graph.h"


TEST(GRAPH, EMPTY_CONSTRUCTOR_CHECKS_EMPTY) {
	Graph g = Graph();
	EXPECT_TRUE(g.isEmpty());
	EXPECT_EQ(g.getNumEdges(), 0);
	EXPECT_EQ(g.getNumVertices(), 0);
}

TEST(GRAPH, IS_EXIST) {
	Graph g = Graph();
	EXPECT_TRUE(g.add(1, 2, 10));
	EXPECT_TRUE(g.isExist(1));
	EXPECT_FALSE(g.isExist(4));
}

TEST(GRAPH, IS_CONNECTED) {
	Graph g = Graph();
	EXPECT_TRUE(g.add(1, 2, 10));
	EXPECT_TRUE(g.isConnected(1, 2));
	EXPECT_FALSE(g.isConnected(3, 2));
}

TEST(GRAPH, ADD_VERTEX) {
	Graph g = Graph();
	EXPECT_TRUE(g.add(1, 2, 10)); // graph is empty
	EXPECT_TRUE(g.add(1, 3, 20)); // v1 exists only
	EXPECT_TRUE(g.add(4, 3, 30)); // v2 exists only
	EXPECT_TRUE(g.add(3, 2, 40)); // both exists but not connected
	EXPECT_TRUE(g.add(5, 6, 50)); // neither exist & not empty
	EXPECT_FALSE(g.add(1, 2, 10)); // bec. already exits
}

TEST(GRAPH, CHECK_SIZE) {
	Graph g = Graph();
	EXPECT_TRUE(g.add(1, 2, 10)); 
	EXPECT_TRUE(g.add(1, 3, 20)); 
	
	EXPECT_FALSE(g.isEmpty());
	EXPECT_EQ(g.getNumEdges(), 2);
	EXPECT_EQ(g.getNumVertices(), 3);
}

TEST(GRAPH, CLEAR) {
	Graph g = Graph();
	EXPECT_TRUE(g.add(1, 2, 10));
	EXPECT_TRUE(g.add(1, 3, 20));

	EXPECT_FALSE(g.isEmpty());
	EXPECT_EQ(g.getNumEdges(), 2);
	EXPECT_EQ(g.getNumVertices(), 3);
	
	g.clear();

	EXPECT_TRUE(g.isEmpty());
	EXPECT_EQ(g.getNumEdges(), 0);
	EXPECT_EQ(g.getNumVertices(), 0);
}

TEST(GRAPH, REMOVE) {
	Graph g = Graph();
	
	EXPECT_TRUE(g.add(1, 2, 10));
	EXPECT_TRUE(g.add(1, 3, 20));
	EXPECT_EQ(g.getNumEdges(), 2);
	EXPECT_TRUE(g.isConnected(1, 2));
	EXPECT_EQ(g.getNumVertices(), 3);

	EXPECT_FALSE(g.remove(4, 5)); // nodes don't exist
	EXPECT_FALSE(g.remove(3, 2)); // not connected
	
	EXPECT_TRUE(g.remove(1, 2)); 
	EXPECT_EQ(g.getNumEdges(), 1);
	EXPECT_FALSE(g.isConnected(1, 2));
	EXPECT_EQ(g.getNumVertices(), 2); // vertex 2 is removed
}

TEST(GRAPH, EDGE_WEIGHT) {
	Graph g = Graph();
	EXPECT_TRUE(g.add(1, 4, 10));
	EXPECT_EQ(g.getEdgeWeight(1, 4), 10);
	EXPECT_EQ(g.getEdgeWeight(1, 3), -1); // don't exist
}


TEST(GRAPH, DFS) {
	Graph g = Graph();
	EXPECT_TRUE(g.add(1, 4, 10));
	EXPECT_TRUE(g.add(4, 5, 20));
	EXPECT_TRUE(g.add(4, 3, 10));
	EXPECT_TRUE(g.add(5, 6, 20));
	EXPECT_TRUE(g.add(3, 2, 10));

	string dfs = g.depthFirstTraversal(1);
	EXPECT_EQ(dfs, "143256");
}

TEST(GRAPH, BFS) {
	Graph g = Graph();
	EXPECT_TRUE(g.add(1, 4, 10));
	EXPECT_TRUE(g.add(4, 5, 20));
	EXPECT_TRUE(g.add(4, 3, 10));
	EXPECT_TRUE(g.add(5, 6, 20));
	EXPECT_TRUE(g.add(3, 2, 10));

	string dfs = g.breadthFirstTraversal(1);
	EXPECT_EQ(dfs, "145362");
}