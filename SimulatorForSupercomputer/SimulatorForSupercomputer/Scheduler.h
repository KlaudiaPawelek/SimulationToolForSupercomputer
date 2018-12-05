#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once
#include "Queue.h"
#include "Users.h"
#include <vector>

using namespace std;

class Scheduler
{
public:
	vector<Queue> queue;

public:
	Scheduler();
	~Scheduler();
	void GetNewJobs(Users users);
	void PutJobIntoQueue(Job &job);
};

#endif

