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
	vector<Job> *job = new vector<Job>;
public:
	Student();
	Student(int id);
	~Student();

	int GetNumbersOfJobs();
	void CreateJob(int amount);
	Job &GetJob(int i);
	void SetStatusOfJob(Job &job, bool inQueue, bool isDone);

};
#endif

