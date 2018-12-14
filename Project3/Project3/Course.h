#ifndef COURSE_H
#define COURSE_H

#pragma once
#include "Student.h"
#include <vector>

using namespace std;

class Course
{
public:
	enum TypeOfCourse
	{
		SoftwareEngineering = 0,
		ComputerMachineVision = 1,
		ComputerAidedEngineering = 2,
	};
	TypeOfCourse typeOfCourse;
	int numberOfStudents; //in given course
	int budget;
	vector<Student> student;
	vector<Job> jobs;
public:
	Course();
	Course(TypeOfCourse typeOfCourse, int numberOfStudents, int budget);
	~Course();

	vector<Job> *GetJobs();
	int GetNumberOfStudents();
	int GetBudget();
};

#endif

