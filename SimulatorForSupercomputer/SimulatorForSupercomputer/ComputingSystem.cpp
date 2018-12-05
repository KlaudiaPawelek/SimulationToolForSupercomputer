#include "pch.h"
#include "ComputingSystem.h"


ComputingSystem::ComputingSystem()
{
	this->storage = Storage(Storage::TypeOfStorage::SSD);
	this->nodes.resize(this->amountNodes);
	for (int i = 0; i<this->amountNodes; i++)
	{
		this->nodes[i] = Nodes(Nodes::TypeOfNode::accelerated);
	}
}


ComputingSystem::~ComputingSystem()
{
}
