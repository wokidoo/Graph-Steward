#include <iostream>
#include "driver.h"

driver::driver(int nodes, int edges)
{
	vertPtr = new Vertex[nodes];
	edgePtr = new Edge[edges];
	numEdges = edges;
	numVert = nodes;
}
driver::~driver()
{
	delete[]vertPtr;
	delete[]edgePtr;
}
Vertex* driver::getVert(int index)
{
	if (index >= 0 && index < numVert)
		return &vertPtr[index];
	else
		return nullptr;
}
Edge* driver::getEdge(int index)
{
	if (index >= 0 && index < numEdges)
		return &edgePtr[index];
	else
		return nullptr;
}

void driver::setVertValues()
{
	int input;
	for (int x{ 0 }; x < numVert; x++)
	{
		std::cout << "Vertex " << vertPtr[x].getID() << "\nValue: ";
		std::cin >> input;
		vertPtr[x].setValue(input);
	}
}

void driver::setEdges()
{
	int input;
	Vertex starting;
	Vertex Ending;
	std::cout << "Using the index value, connect vertices as desired\n";
	for (int x{ 0 }; x < numVert; x++)
	{
		std::cout<<"Index "<<x<< ": Vertex " << vertPtr[x].getID() << " ,Value: " << vertPtr[x].getValue() << "\n";
	}
	for (int x{ 0 }; x < numEdges; x++)
	{
		std::cout<< " Connect vertex @ index ";
		std::cin >> input;
		edgePtr[x].setStart(vertPtr[input]);
		std::cout << " with vertex @ index ";
		std::cin >> input;
		edgePtr[x].setEnd(vertPtr[input]);
		std::cout << "\n";
	}
}

void driver::passToGraph(Directedgraph& t_graph)
{
	for (int x{ 0 }; x < numVert; x++)
	{
		t_graph.addVertex(vertPtr[x]);
	}
	for (int x{ 0 }; x < numVert; x++)
	{
		t_graph.addEdge(edgePtr[x]);
	}
}

void driver::useGraphFunctionality(Directedgraph& t_graph)
{
	bool exit{ false };
	int input;
	while (!exit)
	{
		std::cout << "Select an option\n1. wipe graph\n2. display graph\n3. exit\n4. remove edge\n5. add edge\n6. remove vertex\n7. add vertex";
		std::cin >> input;
		switch (input)
		{
		case 1:
			t_graph.clean();
			std::cout << "\nGraph cleared\n";
			break;
		case 2:
			t_graph.display();
			break;
		case 3:
			exit = true;
			std::cout << "\nEnding Functionality\n";
			break;
		case 4:
			std::cout << "\nInput the index of the edge you would like to remove ";
			std::cin >> input;
			t_graph.removeEdge(edgePtr[input]);
			break;
		case 5:
			std::cout << "\nInput the index of the edge you would like to add ";
			std::cin >> input;
			t_graph.addEdge(edgePtr[input]);
			break;
		case 6:
			std::cout << "\nInput the index of the vertex you would like to remove ";
			std::cin >> input;
			t_graph.removeVertex(vertPtr[input]);
			break;
		case 7:
			std::cout << "\nInput the index of the vertex you would like to add ";
			std::cin >> input;
			t_graph.addVertex(vertPtr[input]);
			break;
		}
	}
	
}