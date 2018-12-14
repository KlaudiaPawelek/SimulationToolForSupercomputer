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
//private
	int jobID;
	bool inQueue;
	bool done;
	int createTime;
	int putIntoQueueTime;
	int inQueueTime;
	int executeTime; 
	int resourceTime;
public:
	Job();
	Job(TypeOfJob type, int createTime);
	~Job();

	int CreateID();

	void SetInQueueTime(int inQueueTime);
	void SetExecuteTime(int executeTime);
	void SetPutInQueueTime(int putIntoQueueTime);
	void SetResourceTime(int resourceTime);
	void SetJobInQueue(bool inQueue);
	void SetJobIsDone(bool done);

	int GetInQueueTime();
	int GetExecuteTime();
	int GetPutInQueueTime();
	int GetResourceTime();
	int GetCreateTime();
	int GetJobId();
	bool GetJobInQueue();
	bool GetJobIsDone();
};
#endif

