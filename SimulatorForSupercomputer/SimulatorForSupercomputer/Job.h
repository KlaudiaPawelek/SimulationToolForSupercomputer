#ifndef JOB_H
#define JOB_H

#pragma once
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
	bool done;
public:
	Job();
	Job(TypeOfJob type);
	~Job();
	int CreateID();
};
#endif

