 #include "Storage.h"

Storage::Storage()
{

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
