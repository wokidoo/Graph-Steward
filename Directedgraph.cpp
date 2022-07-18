#include <iostream>
#include <vector>
#include <string>
#include "Directedgraph.h"

Directedgraph::Directedgraph(int t_numVert, int t_numEdge)
{
	numberOfEdges = 0;
	numberOfVertices = 0;
	maxNumberOfVertices = t_numVert;
	maxNumberOfEdges = t_numEdge;
	vertices = new Vertex * [t_numVert] {nullptr};
	edges = new Edge * [t_numEdge] {nullptr};
}

Directedgraph::~Directedgraph()
{

	delete[] vertices;
	delete[] edges;
}

bool Directedgraph::addVertex(Vertex& t_v)
{
	if (numberOfVertices < maxNumberOfVertices)
	{
		if (!searchVertex(t_v))
		{
			vertices[numberOfVertices] = &t_v;
			numberOfVertices++;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Directedgraph::addVertices(Vertex* t_vertex)
{
	return true;
}

bool Directedgraph::removeVertex(Vertex& t_v)
{
	bool removed{false};
	if (&t_v == nullptr)
		return false;
	for (int index = 0; index < maxNumberOfVertices; index++)
	{
		if (vertices[index] != nullptr) 
		{
			if (vertices[index]->getID() == t_v.getID())
			{
				if (index == maxNumberOfVertices - 1)
				{
					vertices[index] = nullptr;
					removed = true;
				}
				else
				{
					vertices[index] = vertices[index + 1];
					removed = true;
				}
			}
		}
	
	}
	if (removed)
		numberOfVertices--;
	return removed;
}
bool Directedgraph::addEdge(Edge& t_e)
{
	if (numberOfEdges < maxNumberOfEdges)
	{
		if (!searchEdge(t_e))
		{
			if (!searchVertex(*t_e.getStart()))
				addVertex(*t_e.getStart());
			if(!searchVertex(*t_e.getEnd()))
				addVertex(*t_e.getEnd());
			edges[numberOfEdges] = &t_e;
			numberOfEdges++;
			return true;
		}
		else
		{
			removeVertex(*t_e.getStart());
			removeVertex(*t_e.getEnd());
			return false;
		}
	}
	else
		return false;
}


bool Directedgraph::removeEdge(Edge& t_e)
{
	bool removed{false};
	if (&t_e == nullptr)
		return false;
	for (int index = 0; index < maxNumberOfEdges; index++)
	{
		if(edges[index] != nullptr)
		{
			if (edges[index]->getStart()->getID() == t_e.getStart()->getID() && edges[index]->getEnd()->getID() == t_e.getEnd()->getID())
			{
				if (index == numberOfEdges - 1)
				{
					edges[index] = nullptr;
					removed = true;
				}
				else
				{
					edges[index] = edges[index + 1];
				}
			}
		}
	}
	if(removed)
		numberOfEdges--;
	return removed;
}
bool Directedgraph::searchVertex(const Vertex& t_v)
{
	bool found{ false };
	for (int index = 0; index < maxNumberOfVertices; index++)
	{
		if (vertices[index] != nullptr)
		{
			if (vertices[index] == &t_v)
			{
				found = true;
			}
		}
	}
	return found;
}
bool Directedgraph::searchEdge(const Edge& t_e)
{
	bool found{ false };
	for (int index = 0; index < maxNumberOfEdges; index++)
	{
		if (edges[index] != nullptr)
		{
			if (edges[index] == &t_e)
			{
				found = true;
			}
		}
	}
	return found;
}

void Directedgraph::display() const
{
	std::cout << "Graph Vertices & Edges: \n";
	if (numberOfVertices <= 0)
	{
		std::cout << "Empty graph";
	}
	for (int x{ 0 }; x < numberOfVertices; x++)
	{
		std::cout << "v" << vertices[x]->getID() << "->";
		for (int y{ 0 }; y < numberOfVertices; y++)
		{
			for (int edgeNum{ 0 }; edgeNum < numberOfEdges; edgeNum++)
			{
				if (edges[edgeNum]->getStart()->getID() == vertices[x]->getID())
					if (edges[edgeNum]->getEnd()->getID() == vertices[y]->getID())
						std::cout << "v" << vertices[y]->getID()<<"->";
			}
		}
		std::cout << "null\n";
	}
	std::cout << "\n";
}
std::string Directedgraph::toString()const
{
	std::string string;
	for (int x{ 0 }; x < numberOfVertices; x++)
	{
		string.append("v");
		string.append(std::to_string(vertices[x]->getID()));
		string.append("(");
		for (int y{ 0 }; y < numberOfVertices; y++)
		{
			for (int edgeNum{ 0 }; edgeNum < numberOfEdges; edgeNum++)
			{
				if (edges[edgeNum]->getStart()->getID() == vertices[x]->getID())
					if (edges[edgeNum]->getEnd()->getID() == vertices[y]->getID())
					{
						string.append("v");
						string.append(std::to_string(vertices[y]->getID()));
						string.append(",");
					}
						
			}
		}
		string.append("null)");
		
	}
	return string;
}
bool Directedgraph::clean()
{
	for (int index{ 0 }; index < maxNumberOfVertices; index++)
		removeVertex(*vertices[index]);
	for (int index{ 0 }; index < maxNumberOfEdges; index++)
		removeEdge(*edges[index]);
	std::cout << "Graph wiped clean\n";
	return true;
}

bool Directedgraph::operator==(const Directedgraph& graph) const
{
	if (maxNumberOfEdges != graph.maxNumberOfEdges)
		return false;
	if (maxNumberOfVertices != graph.maxNumberOfVertices)
		return false;
	for (int index = 0; index < maxNumberOfEdges; index++)
	{
		if (edges[index] != graph.edges[index])
			return false;
	}
	for (int index = 0; index < maxNumberOfVertices; index++)
	{
		if (vertices[index]->getValue() != graph.vertices[index]->getValue())
			return false;
		if (vertices[index]->getID() != graph.vertices[index]->getID())
			return false;
	}	
	return true;
}
const Directedgraph& Directedgraph::operator=(const Directedgraph& graph)
{
	if (!(*this == graph))
	{
		maxNumberOfEdges = graph.maxNumberOfEdges;
		maxNumberOfVertices = graph.maxNumberOfVertices;
		numberOfEdges = graph.numberOfEdges;
		numberOfVertices = graph.numberOfEdges;
		for (int index = 0; index < maxNumberOfEdges; index++)
			edges[index] = graph.edges[index];
		for (int index = 0; index < maxNumberOfVertices; index++)
			vertices[index] = graph.vertices[index];
		return *this;
	}
	return *this;
		
}
Directedgraph& Directedgraph::operator+(const Directedgraph& graph) const
{
	Directedgraph temp(maxNumberOfVertices + graph.maxNumberOfVertices, maxNumberOfEdges + graph.maxNumberOfEdges);
	for (int index = 0; index < maxNumberOfEdges; index++)
	{
		temp.addEdge(*this->edges[index]);
	}
	for (int index = {maxNumberOfEdges}; index < temp.maxNumberOfEdges; index++)
	{
		temp.addEdge(*graph.edges[index]);
	}
	for (int index = 0; index < maxNumberOfVertices; index++)
	{
		temp.addVertex(*this->vertices[index]);
	}
	for (int index = { maxNumberOfEdges }; index < temp.maxNumberOfVertices; index++)
	{
		temp.addVertex(*graph.vertices[index]);
	}
	return temp;
}
Directedgraph& Directedgraph::operator++()
{
	for (int index = 0; index < maxNumberOfEdges; index++)
		edges[index]->incWeight();
	return *this;
}
Directedgraph& Directedgraph::operator++(int)
{
	Directedgraph temp = *this;
	for (int index = 0; index < maxNumberOfEdges; index++)
		edges[index]->incWeight();
	return temp;
}
bool Directedgraph::operator<(const Directedgraph& graph) const
{
	int thisWeight=0;
	int graphWeight=0;
	for (int index = 0; index < maxNumberOfEdges; index++)
	{
		thisWeight += edges[index]->getWeight();
	}
	for (int index = 0; index < graph.maxNumberOfEdges; index++)
	{
		thisWeight += graph.edges[index]->getWeight();
	}
	return (thisWeight > graphWeight);
}

std::ostream& operator<<(std::ostream& output, const Directedgraph& graph)
{
	output << graph.toString();
	return output;
}
