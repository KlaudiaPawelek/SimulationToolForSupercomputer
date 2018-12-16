 #include "Processor.h"

// Default empty constructor.
Processor::Processor() 
{
}

// Constructor with parameters
Processor::Processor(TypeOfProcessor type, int id)
{
	this->type = type;
	this->id = id;
	this->busy = false;
}

// Default empty destructor.
Processor::~Processor()
{
}

// Return unique processor id
int Processor::GetIdProcessor()
{
	return this->id;
}

// Return information, if processor is busy
bool Processor::ifBusy()
{
	return this->busy;
}
