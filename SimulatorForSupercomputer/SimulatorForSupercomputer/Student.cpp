#include "pch.h"
#include "Student.h"


Student::Student()
{

}

Student::Student(int id)
{
	this->id = id;
	CreateJob(2);
}

Student::~Student()
{
}

int Student::getNumbersOfJobs()
{
	return job.size();
}

void Student::CreateJob(int amount)
{
	this->job.resize(amount);
	for (int i = 0; i < amount; i++)
	{
		this->job[i] = Job(Job::small);
	}

}

Job Student::getJob(int i)
{

	return this->job[i];
}
