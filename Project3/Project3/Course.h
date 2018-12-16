#ifndef COURSE_H
#define COURSE_H

#pragma once
#include "Student.h"
#include <vector>

using namespace std;
/**
	Course class includes vector of objects from Student class and Jobs class.
	Class has also enum TypeOfCourse and also some private attributes.
	Course class calles in constructor, Student's constructor.
**/
class Course
{
public:
	/**
		Three different types of available course.
	**/
	enum TypeOfCourse
	{
		SoftwareEngineering = 0,
		ComputerMachineVision = 1,
		ComputerAidedEngineering = 2,
	};
	/**
		Type of course based on enum.
	**/
	TypeOfCourse typeOfCourse;
	/**
		Vector of objects from Student class.
	**/
	vector<Student> student;
	/**
		Vector of objects from Job class.
	**/
	vector<Job> jobs;

private:
	/**
		Number of studens in given course.
	**/
	int numberOfStudents; 
	/**
		Budget for each course.
	**/
	int budget;


public:
	/**
		Default empty constructor.
	**/
	Course();
	/**
		Constructor with parameters. Create students for each type of course with given budget.
		@param TypeOfCourse typeOfCourse - type of course from enum.
		@param int numberOfStudent - number of student for given course.
		@param int budget - budget for each course.
	**/
	Course(TypeOfCourse typeOfCourse, int numberOfStudents, int budget);
	/**
		Default destructor.
	**/
	~Course();
	/**
		Accessor.
		Return vector of pointers to object Job. Each student has some job.
		@return vector<Job> - pointer to objects.
	**/
	vector<Job> *GetJobs();
	/**
		Accessor.
		Return number of students from given course.
		@return int - number of student from fiven course.
	**/
	int GetNumberOfStudents();
	/**
		Accessor.
		Return budget of given course.
		@return int - budget for given course.
	**/
	int GetBudget();
};

#endif

