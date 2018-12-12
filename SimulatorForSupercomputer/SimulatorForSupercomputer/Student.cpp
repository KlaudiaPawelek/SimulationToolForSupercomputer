#include "pch.h"
#include "Student.h"


Student::Student()
{

}

Student::Student(int id)
{
	this->id = id; 
}

Student::~Student()
{
}

int Student::GetNumbersOfJobs()
{
	return (*job).size();
}

void Student::CreateJob(int amount, vector<int> createTime)
{
	(*job).resize(amount);
	for (int i = 0; i < amount; i++)
	{
		(*job)[i] = Job(Job::_small, createTime[i]);
	}

}

Job &Student::GetJob(int i)
{
	//SetStatusOfJob((*job)[i], true, false);
	return (*job)[i];	
}

void Student::SetStatusOfJob(Job &job, bool inQueue, bool isDone)
{
	job.inQueue = inQueue;
	job.done = isDone;
}
