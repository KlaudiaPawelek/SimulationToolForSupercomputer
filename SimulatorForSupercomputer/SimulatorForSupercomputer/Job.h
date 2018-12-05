#ifndef JOB_H
#define JOB_H

#pragma once
#include <vector>
extern int _ID_;
using namespace std;

class Job
{
public:
	enum TypeOfJob
	{
		small = 0,
		medium = 1,
		huge = 2,
	};
	TypeOfJob type;
	int jobID;
	bool inQueue;
public:
	Job();
	Job(TypeOfJob type);
	~Job();
	void TakeResources();
	int CreateID();
};
#endif

