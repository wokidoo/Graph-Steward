#pragma once
#include <iostream>
#include "Directedgraph.h"

class driver 
{
public:
	driver(int nodes, int edges);
	~driver();
	Vertex* getVert(int index);
	Edge* getEdge(int index);
	void setVertValues();
	void setEdges();
	void passToGraph(Graph& t_graph);
	void useGraphFunctionality(Graph* t_graph);
private:
	Vertex* vertPtr;
	Edge* edgePtr;
	int numEdges;
	int numVert;
};