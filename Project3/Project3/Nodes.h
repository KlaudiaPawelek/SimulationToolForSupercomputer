#ifndef NODES_H
#define NODES_H

#pragma once
#include "Processor.h"
#include <vector>

/**
	Global variable to create unique id number for each node.
**/
extern int _ID_NODE;
using namespace std;

/**
	Node class is responsible for "store" different types of processor in different types of nodes.
	Three different types of node can be created: traditional, accelerated, specialized.
**/

class Nodes
{
public: 
	/**
		Enum type.
		Available types of nodes: 
		Traditional for multicore CPU.
		Accelerated for GPU for computations.
		Specialized for GPU for rendering and visualization.
	**/
	enum TypeOfNode
	{
		traditional = 0,
		accelerated = 1,
		specialized = 2,
	};
	/**
		Type of node: traditional, accelerated or specialized.
	**/
	TypeOfNode type;
	/**
		Vector of pointers to Processor object = Node.
	**/
	vector<Processor> *processors = new vector<Processor>;	
private:	
	/**
		Each node contains 16 processors of given type.
	**/
	static const int amountProcessors = 16;
	/**
		If node is busy by any job.
	**/
	bool busy;
	/**
		Unique id for node.
	**/
	int idNode;
public:
	/**
		Default constructor.
	**/
	Nodes();
	/**
		Constructor with type of created node.
		@param TypeOfNode type - type of Node: traditional, accelerated, specialized.
		@param bool busy - if node is busy by any job.
	**/
	Nodes(TypeOfNode type, bool busy);
	/**
		Default, empty constructor.
	**/
	~Nodes();

	/**
		Create unique int id for each Node object.
		@return int
	**/
	int CreateID();
	/**
		Get vector of pointers to Processor from given Node.
		@return vector<Processor>
	**/
	vector<Processor> *GetProcessors();
	/**
		Return information: if node is busy by any job.
		@return bool
	**/
	bool IfBusy();
	/**
		Return information about node id.
		@return int
	**/
	int GetId();
	/**
		Change value of busy variable.
		@param int busy 
		@return void
	**/
	void SetBusy(int busy);
};

#endif