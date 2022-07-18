#pragma once
#include <iostream>
#include "Vertex.h"

class Edge
{
public:
	Edge();
	Edge(const Edge& t_edge);
	Edge(Vertex& t_starting, Vertex& t_ending)
	{
		startVert = &t_starting;
		endVert = &t_ending;
		weight = 0;
	}
	~Edge();
	void setStart(Vertex& t_vertex);
	void setEnd(Vertex& t_vertex);
	void setWeight(int t_weight);
	Vertex* getStart();
	Vertex* getEnd();
	int getWeight();
	void incWeight() { weight++; }
	/*int getNTraveled() { return nTraveled; }*/
	/*void incNTraveled() { nTraveled++; }
	void zeroNTraveled() { nTraveled = 0; }*/

private:
	/*int nTraveled{ 0 };*/
	int weight;
	Vertex* startVert;
	Vertex* endVert;
};