#ifndef QUEUE_H
#define QUEUE_H

#pragma once
#include "Job.h"
#include <vector>

using namespace std;

class Queue
{
public:
	enum TypeOfJobQueue
	{
		_short = 0,
		medium = 1,
		large = 2,
		huge = 3,
	};
	TypeOfJobQueue type;
	vector<Job> queue;

public:
	Queue();
	Queue(TypeOfJobQueue type);
	~Queue();
	

};

#endif
