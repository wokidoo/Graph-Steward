#pragma once
#include <iostream>
#include "Vertex.h"

int Vertex::counterID=0;

Vertex::Vertex() 
{
	value = 0;
}

Vertex::Vertex(const Vertex& t_vert)
{
	value = t_vert.value;
	ID = t_vert.ID;
}

//Vertex::~Vertex()
//{
//	delete value;
//	delete ID;
//	delete start;
//}

void Vertex::setID(int t_ID)
{
	ID = t_ID;
}

void Vertex::setValue(int t_value)
{
	value = t_value;
}

int Vertex::getID()
{
	return ID;
}

int Vertex::getValue()
{
	return value;
}

