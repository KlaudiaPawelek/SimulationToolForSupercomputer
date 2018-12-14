#ifndef COMPUTINGSYSTEM_H
#define COMPUTINGSYSTEM_H

#pragma once
#include "Nodes.h"
#include "Storage.h"
#include <vector>

using namespace std;

class ComputingSystem
{
public:
	static const int amountNodes = 128;
	vector<Nodes> *nodesTraditional = new vector<Nodes>;
	vector<Nodes> *nodesAccelerated = new vector<Nodes>;
	vector<Nodes> *nodesSpecialized = new vector<Nodes>;
	static const int amountTraditionalNodes = 20;
	static const int amountAcceleratedNodes = 44;
	static const int amountSpecializedNodes = 64;
	static const int constantOperationalCostPerHour_Traditional = 0.01;
	static const int constantOperationalCostPerHour_Accelerated = 0.5;
	static const int constantOperationalCostPerHour_Specialized = 1;
	Storage storage;
public:
	ComputingSystem();
	~ComputingSystem();
	vector<Nodes> *GetNodes(Nodes::TypeOfNode type);
	int GetAmountOfNodes(Nodes::TypeOfNode type);
};

#endif

