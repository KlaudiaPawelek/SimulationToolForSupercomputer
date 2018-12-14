 
#include "Course.h"


Course::Course()
{

}

Course::Course(TypeOfCourse typeOfCourse, int numberOfStudents, int budget)
{
	this->typeOfCourse = typeOfCourse;
	this->numberOfStudents = numberOfStudents;
	this->student.resize(numberOfStudents);
	for (int i = 0; i < numberOfStudents; i++)
	{
		this->student[i] = Student(i);
	}
	this->budget = budget;
}

Course::~Course()
{
	//to do
}

vector<Job>* Course::GetJobs()
{
	for (int i = 0; i < this->student.size(); i++)
	{
		for (int j = 0; j < this->student[i].GetNumbersOfJobs(); j++)
		{
			this->jobs.push_back(this->student[i].GetJob(j));
		}
		
	}
	return &jobs;
}

int Course::GetNumberOfStudents()
{
	return this->numberOfStudents;
}

int Course::GetBudget()
{
	return this->budget;
}
