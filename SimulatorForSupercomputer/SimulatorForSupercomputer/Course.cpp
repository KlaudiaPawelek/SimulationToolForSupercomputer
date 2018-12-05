#include "pch.h"
#include "Course.h"


Course::Course()
{

}

Course::Course(TypeOfCourse typeOfCourse, int numberOfStudents)
{
	this->typeOfCourse = typeOfCourse;
	this->numberOfStudents = numberOfStudents;
	this->student.resize(numberOfStudents);
	for (int i = 0; i < numberOfStudents; i++)
	{
		this->student[i] = Student(i);
	}
}

Course::~Course()
{
	//to do
}

vector<Job>* Course::GetJobs()
{
	for (int i = 0; i < this->student.size(); i++)
	{
		for (int j = 0; j < this->student[i].getNumbersOfJobs(); j++)
		{
			this->jobs.push_back(this->student[i].getJob(j));
		}
		
	}
	return &jobs;
}
