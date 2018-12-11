#ifndef NODES_H
#define NODES_H

#pragma once
#include "Processor.h"
#include <vector>
extern int _ID_NODE;
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
	vector<Processor> *processors = new vector<Processor>;
	bool busy;
	int idNode;
public:
	/**
	* Default constructor.
	**/
	Nodes();
	/**
	* Constructor with type of created node
	**/
	Nodes(TypeOfNode type, bool busy);
	~Nodes();

	int CreateID();
	vector<Processor> *getProcessors();
};

#endif