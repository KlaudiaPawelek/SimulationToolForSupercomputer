#ifndef JOB_H
#define JOB_H

#pragma once
/**
	_ID_ is important counter, which gives for each created job unique integer number.
	It is incremented in CreateID method.
**/
extern int _ID_;
using namespace std;

/**
	Job class is responsible for create object of type Job, which are created by simulaed users like in Student class.
	Class includes mainly attributes and some accessors.
**/

class Job
{
public:
	/**
		TypeOfJob is an enum. It describes available types of job like: small, medium, huge.
		Small are for student mainly (in current version of the simulation tool software).
		Medium and Huge for Researcher and Staff (in the further versions).
	**/
	enum TypeOfJob
	{
		_small = 0,
		medium = 1,
		huge = 2,
	};
	/**
		Type of job.
	**/
	TypeOfJob type;
	/**
		Unique jobID. Check _ID_ global variable.
	**/
	int jobID;
	/**
		Create time is a time, when user create job.
		Value is described by exponential distribution method from SimulationTool class.
	**/
	int createTime;

private:
	/**
		Variable, which is filled furing working of application. 
		If job is in the queue.
	**/
	bool inQueue;
	/**
		Variable, which is filled furing working of application.
		If job has been done.
	**/
	bool done;
	/**
		Variable, which is filled furing working of application.
		When job has been put into queue.
	**/
	int putIntoQueueTime;
	/**
		Variable, which is filled furing working of application.
		How much time job was in the queue.
		From PutIntoQueue to Execute Time.
	**/
	int inQueueTime;
	/**
		Variable, which is filled furing working of application.	
		How long job was executed.
	**/
	int executeTime; 
	/**
		Variable, which is filled furing working of application.
		When did job get nodes/storage.
	**/
	int resourceTime;
public:
	/**
		Default, empty constructor.
	**/
	Job();
	/**
		Constructor with parameters.
		@param TypeOfJob type - which type of job is create: small, medium, huge.
		@param int createTime - described by exponential distribution.
	**/
	Job(TypeOfJob type, int createTime);
	/**
		Default, empty destructor.
	**/
	~Job();

	/**
		Access to private inQueueTime variable.
		@param int inQueueTime
		@return void
	**/
	void SetInQueueTime(int inQueueTime);
	/**
		Access to private executeTime variable.
		@param int executeTime
		@return void
	**/
	void SetExecuteTime(int executeTime);
	/**
		Access to private inQueueTime variable.
		@param int inQueueTime
		@return void
	**/
	void SetPutInQueueTime(int putIntoQueueTime);
	/**
		Access to private resourceTime variable.
		@param int resourceTime
		@return void
	**/
	void SetResourceTime(int resourceTime);
	/**
		Access to private inQueue variable.
		@param bool inQueue
		@return void
	**/
	void SetJobInQueue(bool inQueue);
	/**
		Access to private done variable.
		@param bool done
		@return void
	**/
	void SetJobIsDone(bool done);


	/**
		Access to private inQueueTime variable.
	**/
	int GetInQueueTime();
	/**
		Access to private executeTime variable.
	**/
	int GetExecuteTime();
	/**
		Access to private PutInQueueTime variable.
	**/	
	int GetPutInQueueTime();
	/**
		Access to private resourceTime variable.
	**/
	int GetResourceTime();
	/**
		Access to public createTime variable.
	**/
	int GetCreateTime();
	/**
		Access to unique job id.
	**/
	int GetJobId();
	/**
		Access to private inQueue bool variable.
	**/
	bool GetJobInQueue();
	/**
		Access to private done bool variable.
	**/
	bool GetJobIsDone();

private:	
	int CreateID();
};
#endif

