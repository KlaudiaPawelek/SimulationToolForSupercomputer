 
#include "Nodes.h"
int _ID_NODE = 0;
Nodes::Nodes()
{

}

Nodes::Nodes(TypeOfNode type, bool busy)
{
	this->type = type;
	this->busy = busy;
	this->idNode = CreateID();
	(*this->processors).resize(this->amountProcessors);
	if (type == 0)
	{
		
		for (int i = 0; i < this->amountProcessors; i++)
		{
			(*this->processors)[i] = Processor(Processor::CPU_multicore, i);
		}
	}
	else if (type == 1)
	{
		
		for (int i = 0; i < this->amountProcessors; i++)
		{
			(*this->processors)[i] = Processor(Processor::GPU_computations, i);
		}
	}
	else if (type == 2)
	{
		
		for (int i = 0; i < this->amountProcessors; i++)
		{
			(*this->processors)[i] = Processor(Processor::GPU_rendering, i);
		}
	}
}


Nodes::~Nodes()
{
}

int Nodes::CreateID()
{
	_ID_NODE++;
	return _ID_NODE;
}

vector<Processor> *Nodes::getProcessors()
{
	return processors;
}

bool Nodes::ifBusy()
{
	return this->busy;
}

int Nodes::getId()
{
	return this->idNode;
}
