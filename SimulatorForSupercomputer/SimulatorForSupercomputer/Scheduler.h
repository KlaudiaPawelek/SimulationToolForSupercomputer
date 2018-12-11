#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once
#include "Queue.h"
#include "Users.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <random>

using namespace std;

class Scheduler
{
public:
	vector<Queue> *queue = new vector<Queue>;
	vector<Job> *jobs = new vector<Job>;
public:
	Scheduler();
	~Scheduler();
	void GetNewJobs(Users &users);
	void PutJobIntoQueue(Job &job);
	void DeleteJobFromQueue(Queue &queue, Users &users);
	vector<Queue> *GetQueue();
	int AmountOfJob(Queue::TypeOfJobQueue typOfJobQueue);
	
};

#endif

