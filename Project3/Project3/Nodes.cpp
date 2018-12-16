 #include "Nodes.h"
int _ID_NODE = 0; //global variable

// Default empty constructor.
Nodes::Nodes()
{

}

// Constructor with parameters.
Nodes::Nodes(TypeOfNode type, bool busy)
{
	this->type = type;
	this->busy = busy;
	this->idNode = CreateID();
	(*this->processors).resize(this->amountProcessors);
	
	// TRADITIONAL NODES
	if (type == 0)
	{
		
		for (int i = 0; i < this->amountProcessors; i++)
		{
			// Create processors of given type
			// Save it into vector.
			(*this->processors)[i] = Processor(Processor::CPU_multicore, i);	
		}
	}
	//ACCELERATED NODES
	else if (type == 1)
	{
		
		for (int i = 0; i < this->amountProcessors; i++)
		{
			// Create processors of given type
			// Save it into vector.
			(*this->processors)[i] = Processor(Processor::GPU_computations, i);
		}
	}
	//SPECIALIZED NODES
	else if (type == 2)
	{
		
		for (int i = 0; i < this->amountProcessors; i++)
		{
			// Create processors of given type
			// Save it into vector.
			(*this->processors)[i] = Processor(Processor::GPU_rendering, i);
		}
	}
}

// Default destructor.
Nodes::~Nodes()
{
}

// Create unique id for each node. 
int Nodes::CreateID()
{
	_ID_NODE++; // global variable
	return _ID_NODE;
}

// Return vector of pointers to Processor objects.
vector<Processor> *Nodes::GetProcessors()
{
	return processors;
}

// Return value of busy variable
bool Nodes::IfBusy()
{
	return this->busy;
}

// Return node id.
int Nodes::GetId()
{
	return this->idNode;
}

// Set value of busy variable: true - node is busy, false - node is not busy by job.
void Nodes::SetBusy(int busy)
{
	this->busy = busy;
}
