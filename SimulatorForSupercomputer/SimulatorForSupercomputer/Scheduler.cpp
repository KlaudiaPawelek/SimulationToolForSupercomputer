#include "pch.h"
#include "Scheduler.h"


Scheduler::Scheduler()
{
	this->queue.resize(4);
	this->queue[0] = Queue(Queue::_short);
	this->queue[1] = Queue(Queue::medium);
	this->queue[2] = Queue(Queue::large);
	this->queue[3] = Queue(Queue::huge);

}

Scheduler::~Scheduler()
{
}

void Scheduler::GetNewJobs(Users users)
{
	vector<Job> *jobs;
	for (int j = 0; j < users.course.size(); j++)
	{
		jobs = users.course[j].GetJobs();
		for (int i = 0; i < (*jobs).size(); i++)
		{
			PutJobIntoQueue((*jobs)[i]);
		}
	}
}

void Scheduler::PutJobIntoQueue(Job &job)
{
	if (job.type == Job::small)
	{
		job.inQueue = true;
		this->queue[0].queue.push_back(job);
		
	}
}


