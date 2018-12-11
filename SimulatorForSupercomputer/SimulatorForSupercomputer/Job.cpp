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
	this->done = false;
}


Job::~Job()
{
	
}


int Job::CreateID()
{
	_ID_ ++;
	return _ID_;
}
