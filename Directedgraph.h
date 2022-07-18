#pragma once
#include<iostream>
#include <iomanip>
#include "Graph.h"


class Directedgraph:public Graph
{

public:
	Directedgraph(int t_numVert, int t_numEdge);
	virtual ~Directedgraph();
	virtual bool addVertex(Vertex& t_v);
	virtual bool removeVertex(Vertex& t_v);
	virtual bool addEdge(Edge& t_e);
	virtual bool removeEdge(Edge& t_e);
	virtual bool searchVertex(const Vertex& t_v);
	virtual bool searchEdge(const Edge& t_e);
	virtual void display() const;
	virtual bool clean();
	virtual void printAdj(Vertex&);
	int getNumEdge() { return numberOfEdges; }
	int getNumVert() { return numberOfVertices; }
	int getMaxNumEdge() { return maxNumberOfEdges; }
	int getMaxNumVert() { return maxNumberOfVertices; }
	Vertex* getVert(int index) { return vertices[index]; }
	Edge* getEdge(int index) { return edges[index]; }

private:
	int maxNumberOfEdges;
	int maxNumberOfVertices;
	int numberOfVertices;
	int numberOfEdges;
	Vertex** vertices;
	Edge** edges;
};