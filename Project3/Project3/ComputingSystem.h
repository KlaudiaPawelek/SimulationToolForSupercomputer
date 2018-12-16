#ifndef COMPUTINGSYSTEM_H
#define COMPUTINGSYSTEM_H

#pragma once
#include "Nodes.h"
#include "Storage.h"
#include <vector>

using namespace std;
/**
	ComputingSystem class includes objects from Nodes class and Storage class.
	The constructor of this class calls constructors from Node class and Storage class.
	In general, ComputingSystem class simulates computing environment.
	Additionaly, it includes some static values like number of nodes for each type and costs.
**/

class ComputingSystem
{
public:
	/**
		Vector of objects (*pointer) for tranditional nodes. Traditional nodes include only multicore CPUs.
	**/
	vector<Nodes> *nodesTraditional = new vector<Nodes>;
	/**
		Vector of objects (*pointer) for accelerated nodes. Accelerated nodes include GPUs dedicated for computations.
	**/
	vector<Nodes> *nodesAccelerated = new vector<Nodes>;
	/**
		Vector of objects (*pointer) for specialized nodes. Specialized nodes include GPUs for rendering and visualization
	**/
	vector<Nodes> *nodesSpecialized = new vector<Nodes>;
	/**
		Object from Storage class.
	**/
	Storage storage;
private:
	/**
		General amount of nodes. Traditional + accelerated + specialized = 128;
	**/
	static const int amountNodes = 128;
	/**
		Amount of traditional nodes. 20% of amountNodes. For Students.
	**/
	static const int amountTraditionalNodes = 20;
	/**
		Amount of accelerated node. 44% of amountNodes. For Researchers.
	**/
	static const int amountAcceleratedNodes = 44;
	/**
		Ampunt of specialized nodes. 50% of amountNodes. For Researchers, staff.
	**/
	static const int amountSpecializedNodes = 64;

	/**
		Operational cost per hour for traditional nodes.
	**/
	static const int constantOperationalCostPerHour_Traditional = 0.01;
	/**
		Operational cost per hour for accelerated nodes.
	**/
	static const int constantOperationalCostPerHour_Accelerated = 0.5;
	/**
		Operational cost per hour for specialzied nodes.
	**/
	static const int constantOperationalCostPerHour_Specialized = 1;
	
public:
	/**
		Default constructor. It calls constructors from Nodes class and Storage class. 
		Vector like nodesSpecialized and others are filled by objects.
	**/
	ComputingSystem();
	/**
		Default destructor.
	**/
	~ComputingSystem();


	/**
		Accessor, which returns (pointer) vector of Nodes of given type.
		@param Nodes::TypeOfNode type - type of node.
		@return vector<Nodes>
	**/
	vector<Nodes> *GetNodes(Nodes::TypeOfNode type);
	/**
		Accessor, which returns amunt of Nodes of given type from private attributes.
		@param Nodes::TypeOfNode type - type of node.
		@return int - number of nodes of given type.
	**/
	int GetAmountOfNodes(Nodes::TypeOfNode type);
};

#endif

