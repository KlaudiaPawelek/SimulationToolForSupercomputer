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
		_small = 0,
		medium = 1,
		huge = 2,
	};
	TypeOfJob type;
	int jobID;
	bool inQueue;
	bool done;
	int time;
public:
	Job();
	Job(TypeOfJob type, int time);
	~Job();
	int CreateID();
};
#endif

