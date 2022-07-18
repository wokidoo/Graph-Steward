#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"

template<class T>
class undirectedgraph :public Graph<T>
{
public:
	undirectedgraph();
	undirectedgraph(int t_numVert, int t_numEdge);
	virtual ~undirectedgraph();

	int getNumEdge() { return numberOfEdges; }
	int getNumVert() { return numberOfVertices; }
	int getMaxNumEdge() { return maxNumberOfEdges; }
	int getMaxNumVert() { return maxNumberOfVertices; }
	virtual bool addVertex(Vertex<T>&);
	virtual bool removeVertex(Vertex<T>&);
	virtual bool addEdge(Edge<T>&);
	virtual bool removeEdge(Edge<T>&);
	virtual bool searchVertex(const Vertex<T>&);
	virtual bool searchEdge(const Edge<T>&);
	virtual void display() const;
	virtual bool clean();
	virtual void printAdj(Vertex<T>&);
	virtual bool findAdj(Vertex<T>*);
	virtual bool findValue(T);
	virtual Vertex<T>* getVert(int index) { return vertices[index]; }
	virtual Edge<T>* getEdge(int index) { return edges[index]; }

private:
	int maxNumberOfEdges;
	int maxNumberOfVertices;
	int numberOfVertices;
	int numberOfEdges;
	Vertex<T>** vertices;
	Edge<T>** edges;
};

template<class T>
undirectedgraph<T>::undirectedgraph()
{
	numberOfEdges = 0;
	numberOfVertices = 0;
	maxNumberOfVertices = 0;
	maxNumberOfEdges = 0;
	vertices = nullptr;
	edges = nullptr;
}

template<class T>
undirectedgraph<T>::undirectedgraph(int t_numVert, int t_numEdge)
{
	numberOfEdges = 0;
	numberOfVertices = 0;
	maxNumberOfVertices = t_numVert;
	maxNumberOfEdges = t_numEdge;
	vertices = new Vertex<T>*[t_numVert] {nullptr};
	edges = new Edge<T>*[t_numEdge] {nullptr};
}

template<class n>
undirectedgraph<n>::~undirectedgraph()
{

	delete[] vertices;
	delete[] edges;
}

template<class T>
bool undirectedgraph<T>::addVertex(Vertex<T>& t_v)
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

template<class T>
bool undirectedgraph<T>::removeVertex(Vertex<T>& t_v)
{
	int count{ 0 };
	bool removed{ false };
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
	{
		numberOfVertices--;
		for (int index = numberOfEdges - 1; index >= 0; index--)
		{
			if (edges[index]->getEnd()->getID() == t_v.getID() || edges[index]->getStart()->getID() == t_v.getID())
			{
				if (index == numberOfEdges - 1)
					edges[index] = nullptr;
				else
					edges[index] = edges[index + 1];
				numberOfEdges--;
			}
		}
	}
	return removed;
}

template<class T>
bool undirectedgraph<T>::addEdge(Edge<T>& t_e)
{
	if (numberOfEdges < maxNumberOfEdges)
	{
		if (!searchEdge(t_e))
		{
			if (!searchVertex(*t_e.getStart()))
				addVertex(*t_e.getStart());
			if (!searchVertex(*t_e.getEnd()))
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

template<class T>
bool undirectedgraph<T>::removeEdge(Edge<T>& t_e)
{
	bool removed{ false };
	if (&t_e == nullptr)
		return false;
	for (int index = 0; index < maxNumberOfEdges; index++)
	{
		if (edges[index] != nullptr)
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
	if (removed)
		numberOfEdges--;
	return removed;
}

template<class T>
bool undirectedgraph<T>::searchVertex(const Vertex<T>& t_v)
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

template<class T>
bool undirectedgraph<T>::searchEdge(const Edge<T>& t_e)
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

template<class T>
void undirectedgraph<T>::display() const
{
	std::cout << "\nV={";
	for (int index = 0; index < numberOfVertices; index++)
	{
		std::cout << vertices[index]->getID();;
		if (index < numberOfVertices - 1)
			std::cout << ",";
	}
	std::cout << "}";

	std::cout << "\nE={";
	for (int index = 0; index < numberOfEdges; index++)
	{
		std::cout << "(" << edges[index]->getStart()->getID() << "," << edges[index]->getEnd()->getID() << ")";
		if (index < numberOfEdges - 1)
			std::cout << ",";
	}
	std::cout << "}\n";
}

template<class T>
bool undirectedgraph<T>::clean()
{
	for (int index{ 0 }; index < maxNumberOfVertices; index++)
		removeVertex(*vertices[index]);
	for (int index{ 0 }; index < maxNumberOfEdges; index++)
		removeEdge(*edges[index]);
	std::cout << "Graph wiped clean\n";
	return true;
}

template<class T>
void undirectedgraph<T>::printAdj(Vertex<T>& t_vert)
{
	std::cout << "E={";
	for (int index = 0; index < numberOfEdges; index++)
	{
		if (edges[index]->getStart()->getID() == t_vert.getID())
		{
			std::cout << "(" << edges[index]->getStart()->getID() << "," << edges[index]->getEnd()->getID() << ")";
			if (index < numberOfEdges - 1)
				std::cout << ",";
		}
	}
	for (int index = 0; index < numberOfEdges; index++)
	{
		if (edges[index]->getEnd()->getID() == t_vert.getID())
		{
			std::cout << "(" << edges[index]->getStart()->getID() << "," << edges[index]->getEnd()->getID() << ")";
			if (index < numberOfEdges - 1)
				std::cout << ",";
		}
	}
	std::cout << "}\n";
}

template<class T>
bool undirectedgraph<T>::findAdj(Vertex<T>* t_vert)
{
	bool found = false;
	for (int index = 0; index < maxNumberOfEdges; index++)
	{
		if (edges[index]->getStart()->getID() == t_vert->getID() || edges[index]->getEnd()->getID() == t_vert->getID())
			found = true;
	}
	return found;
}

template<class T>
bool undirectedgraph<T>::findValue(T t_val)
{
	for (int index = 0; index < numberOfVertices; index++)
	{
		if (vertices[index]->getValue() == t_val)
			return true;
	}
	return false;
}