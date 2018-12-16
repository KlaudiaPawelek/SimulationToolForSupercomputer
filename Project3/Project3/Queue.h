#ifndef QUEUE_H
#define QUEUE_H

#pragma once
#include "Job.h"
#include <vector>

using namespace std;

/**
	Queue class is responsible to simulate real queue in supercomputer environment.
	Queue class store jobs created by users.
	Scheduler is responsible for ordering jobs in queue.
**/

class Queue
{
public:
	/**
		Enum type with four different types of queue.
		_short is only for small jobs
		medium is for small and mednium jobs
		large is for medium and huge jobs
		huge is only for huge jobs
	**/
	enum TypeOfJobQueue
	{
		_short = 0,
		medium = 1,
		large = 2,
		huge = 3,
	};
	/**
		Type of queue: _short, medium, large, huge.
	**/
	TypeOfJobQueue type;
	/**
		Vector of Job object.
	**/
	vector<Job> queue;

public:
	/**
		Default, empty constructor.
	**/
	Queue();
	/**
		Constructor with paramter.
		@param TypeOfJobQueue type
	**/
	Queue(TypeOfJobQueue type);
	/**
		Default, empty destructor.
	**/
	~Queue();
};

#endif
