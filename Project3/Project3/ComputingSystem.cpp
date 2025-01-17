#include "ComputingSystem.h"

// Constructor, which containt vector of pointers to objects Nodes and Storage.
ComputingSystem::ComputingSystem()
{
	this->storage = Storage(Storage::TypeOfStorage::SSD);
	(*this->nodesTraditional).resize(this->amountTraditionalNodes);
	for (int i = 0; i < this->amountTraditionalNodes; i++)
	{
		(*this->nodesTraditional)[i] = Nodes(Nodes::TypeOfNode::traditional,false);
	}

	(*this->nodesAccelerated).resize(this->amountAcceleratedNodes);
	for (int i = 0; i < this->amountAcceleratedNodes; i++)
	{
		(*this->nodesAccelerated)[i] = Nodes(Nodes::TypeOfNode::accelerated, false);
	}

	(*this->nodesSpecialized).resize(this->amountSpecializedNodes);
	for (int i = 0; i < this->amountSpecializedNodes; i++)
	{
		(*this->nodesSpecialized)[i] = Nodes(Nodes::TypeOfNode::specialized, false);
	}
}

// Default destructor.
ComputingSystem::~ComputingSystem()
{
}

// Return vector of pointer to objects Node of given type.
vector<Nodes> *ComputingSystem::GetNodes(Nodes::TypeOfNode type)
{
	if (type == Nodes::traditional)
		return nodesTraditional;

	//nodes are not available yet
	/*if (type == Nodes::accelerated)
		return nodesAccelerated;
	if (type == Nodes::specialized)
		return nodesSpecialized;*/
}

// Return information about amount of each type of nodes.
int ComputingSystem::GetAmountOfNodes(Nodes::TypeOfNode type)
{
	if (type == Nodes::TypeOfNode::traditional)
		return this->amountTraditionalNodes;
	if (type == Nodes::TypeOfNode::accelerated)
		return this->amountAcceleratedNodes;
	if (type == Nodes::TypeOfNode::specialized)
		return this->amountSpecializedNodes;
}
