 
#include "Processor.h"

Processor::Processor() 
{
}

Processor::Processor(TypeOfProcessor type, int id)
{
	this->type = type;
	this->id = id;
	this->busy = false;
}


Processor::~Processor()
{
}

int Processor::GetIdProcessor()
{
	return this->id;
}

bool Processor::ifBusy()
{
	return this->busy;
}
