#include "pch.h"
#include "Nodes.h"

Nodes::Nodes()
{

}

Nodes::Nodes(TypeOfNode type)
{
	this->type = type;
	this->processors.resize(this->amountProcessors);
	if (type == 0)
	{
		
		for (int i = 0; i < this->amountProcessors; i++)
		{
			this->processors[i] = Processor(Processor::CPU_multicore, i);
		}
	}
	else if (type == 1)
	{
		
		for (int i = 0; i < this->amountProcessors; i++)
		{
			this->processors[i] = Processor(Processor::GPU_computations, i);
		}
	}
	else if (type == 2)
	{
		
		for (int i = 0; i < this->amountProcessors; i++)
		{
			this->processors[i] = Processor(Processor::GPU_rendering, i);
		}
	}
}


Nodes::~Nodes()
{
}
