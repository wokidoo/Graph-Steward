#pragma once
#include <iostream>
#include "Vertex.h"
#include "Edge.h"

class Graph
{
public:
	Graph() {};
	virtual ~Graph() {};
	virtual bool addVertex(Vertex&) = 0;
	virtual bool removeVertex(Vertex&) = 0;
	virtual bool addEdge(Edge&) = 0;
	virtual bool removeEdge(Edge&) = 0;
	virtual bool searchVertex(const Vertex& t_v) = 0;
	virtual bool searchEdge(const Edge& t_e) = 0;
	virtual void display() const = 0;
	virtual bool clean() = 0;
	virtual void printAdj(Vertex&) = 0;

};