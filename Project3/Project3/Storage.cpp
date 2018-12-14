 
#include "Storage.h"

Storage::Storage()
{
	//this->type = TypeOfStorage::SSD;
	//this->generalSize = this->size * this->amount;
}

Storage::Storage(TypeOfStorage type)
{
	this->type = type;
	this->generalSize = this->size * this->amount;
}


Storage::~Storage()
{
}

int Storage::GetGeneralSize()
{
	return this->generalSize;
}
