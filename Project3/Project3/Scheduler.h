#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once
#include "Queue.h"
#include "Users.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <random>
#include <algorithm>

/**
	Global variable which simulates time.
	@see MatchJobToResources method
**/
extern int _CLOCK_;

/**
	Global variable which simulates time.
	@see ExecuteJobs method
**/
extern int _CLOCK2_;
using namespace std;

/**
	Scheduler class is responsible for managing jobs into queue.
	The main rule/constrait: first-come, first-served. FIFO queue.
**/

class Scheduler
{
public:
	/**
		Vector of pointers to Queue objects.
	**/
	vector<Queue> *queue = new vector<Queue>;
	/**
		Vector of pointers to Job objects.
	**/
	vector<Job> *jobs = new vector<Job>;
public:
	/**
		Constructor responsibles for creating different type of empty queues.
		It prepairs queue for created by user jobs.
	**/
	Scheduler();
	/**
		Default destructor.
	**/
	~Scheduler();

	/**
		This method gathers new jobs created by users.
		@param Users &users
		@return void
	**/
	void GetNewJobs(Users &users);
	/**
		This method is responsible for save jobs gathered by GetNewJobs method into queue.
		Additionaly, it is responsible for ordering.
		@param Job &job.
		@return void
	**/
	void PutJobIntoQueue(Job &job);
	/**
		Scheduler is responsible for deleting from queue executed job.
		@param Queue &queue
		@param Users &users
		@return int
	**/
	int DeleteJobFromQueue(Queue &queue, Users &users);

	/**
		Simple getter responsible for access to queue with jobs.
		@return vector<Queue>
	**/
	vector<Queue> *GetQueue();

	/**
		Check number of job in queue.
		@param TypeOfJobQueue
		@return int
	**/
	int AmountOfJob(Queue::TypeOfJobQueue typOfJobQueue);
};

#endif

