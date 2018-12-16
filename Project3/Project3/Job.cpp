 #include "Job.h"
int _ID_ = 0; //global variable

// Default, empty constructor.
Job::Job()
{

}

// Constructor with parameters.
// At the beggining some attributes are zero.
Job::Job(TypeOfJob type, int createTime)
{
	this->type = type;
	this->jobID = CreateID();
	this->inQueue = false;
	this->done = false;
	this->createTime = createTime;
	this->inQueueTime = 0;
	this->executeTime = 0;
	this->resourceTime = 0;
	this->putIntoQueueTime = 0;
}

// Default empty destructor.
Job::~Job()
{
	
}

//Method responsible for create unique interger id for job.
int Job::CreateID()
{
	_ID_ ++;
	return _ID_;
}

//--- Methods GET and SET described in Header File Job.h---

//
// --SET --
//
void Job::SetInQueueTime(int inQueueTime)
{
	this->inQueueTime = inQueueTime;
}

void Job::SetExecuteTime(int executeTime)
{
	this->executeTime = executeTime;
}

void Job::SetPutInQueueTime(int putIntoQueueTime)
{
	this->putIntoQueueTime = putIntoQueueTime;
}

void Job::SetResourceTime(int resourceTime)
{
	this->resourceTime = resourceTime;
}

void Job::SetJobInQueue(bool inQueue)
{
	this->inQueue = inQueue;
}

void Job::SetJobIsDone(bool done)
{
	this->done = done;
}


//
// -- GET --
//
int Job::GetInQueueTime()
{
	return this->inQueueTime;
}

int Job::GetExecuteTime()
{
	return this->executeTime;
}

int Job::GetPutInQueueTime()
{
	return this->putIntoQueueTime;
}

int Job::GetResourceTime()
{
	return this->resourceTime;
}

int Job::GetCreateTime()
{
	return this->createTime;
}

int Job::GetJobId()
{
	return this->jobID;
}

bool Job::GetJobInQueue()
{
	return this->inQueue;
}

bool Job::GetJobIsDone()
{
	return this->done;
}

