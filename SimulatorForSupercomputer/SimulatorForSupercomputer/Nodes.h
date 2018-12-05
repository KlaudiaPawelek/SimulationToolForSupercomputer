#ifndef NODES_H
#define NODES_H

#pragma once
#include "Processor.h"
#include <vector>

using namespace std;

class Nodes
{
public: 
	enum TypeOfNode
	{
		traditional = 0,
		accelerated = 1,
		specialized = 2,
	};
	TypeOfNode type;
	static const int amountProcessors = 16;
	vector<Processor> processors;
public:
	/**
	* Default constructor.
	**/
	Nodes();
	/**
	* Constructor with type of created node
	**/
	Nodes(TypeOfNode type);

	~Nodes();
};

#endif