#pragma once
#include <iostream>
#include "Edge.h"

Edge::Edge()
{
	startVert = nullptr;
	endVert = nullptr;
	weight = 0;
}

Edge::Edge(const Edge& t_edge)
{
	startVert = t_edge.startVert;
	endVert = t_edge.endVert;
	weight = t_edge.weight;
}

Edge::~Edge()
{
	endVert = nullptr;
	startVert = nullptr;
}

void Edge::setStart(Vertex& t_vertex)
{
	startVert = &t_vertex;
}

void Edge::setEnd(Vertex& t_vertex)
{
	endVert = &t_vertex;
}

void Edge::setWeight(int t_weight)
{
	weight = t_weight;
}

Vertex* Edge::getStart()
{
	return startVert;
}
Vertex* Edge::getEnd()
{
	return endVert;
}

int Edge::getWeight()
{
	return weight;
}