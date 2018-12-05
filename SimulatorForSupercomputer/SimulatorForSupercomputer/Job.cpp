#include "pch.h"
#include "Job.h"
int _ID_ = 0;

Job::Job()
{

}

Job::Job(TypeOfJob type)
{
	this->type = type;
	this->jobID = CreateID();
	this->inQueue = false;
}


Job::~Job()
{
}

void Job::TakeResources()
{
	//??
}

int Job::CreateID()
{
	_ID_ ++;
	return _ID_;
}
