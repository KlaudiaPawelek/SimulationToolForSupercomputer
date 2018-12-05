#ifndef STUDENT_H
#define STUDENT_H

#pragma once
#include "Job.h"
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
	int id;
	vector<Job> job;
public:
	Student();
	Student(int id);
	~Student();

	int getNumbersOfJobs();
	void CreateJob(int amount);
	Job getJob(int i);

};
#endif

