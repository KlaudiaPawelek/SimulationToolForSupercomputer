#include "pch.h"
#include "Scheduler.h"


Scheduler::Scheduler()
{
	(*this->queue).resize(4);
	(*this->queue)[0] = Queue(Queue::_short);
	(*this->queue)[1] = Queue(Queue::medium);
	(*this->queue)[2] = Queue(Queue::large);
	(*this->queue)[3] = Queue(Queue::huge);

}

Scheduler::~Scheduler()
{
}

void Scheduler::GetNewJobs(Users &users)
{
	
	for (int i = 0; i < users.course.size(); i++)
	{
		for (int j = 0; j < users.course[i].student.size(); j++)
		{
			for (int k = 0; k < users.course[i].student[j].job->size(); k++)
			{
				jobs->push_back(users.course[i].student[j].GetJob(k));
			}
		}
	}


	for (int i = 0; i < (*jobs).size(); i++)
	{
		PutJobIntoQueue((*jobs)[i]);
	}
	
	
}

void Scheduler::PutJobIntoQueue(Job &job)
{
	if (job.type == Job::_small)
	{
		job.inQueue = true;
		(*this->queue)[0].queue.push_back(job);
		
	}
}

void Scheduler::DeleteJobFromQueue(Queue &queue, Users &users)
{

	queue.queue.erase(queue.queue.begin());
	int sizetmp = queue.queue.size();

	for (int i = 0; i < users.course.size(); i++)
	{
		for (int j = 0; j < users.course[i].student.size(); j++)
		{
			for (int k = 0; k < users.course[i].student[j].job->size(); k++)
			{
				users.course[i].student[j].SetStatusOfJob(users.course[i].student[j].GetJob(k), false, true);
			}
		}
	}
	
}

vector<Queue>* Scheduler::GetQueue()
{
	return queue;
}

int Scheduler::AmountOfJob(Queue::TypeOfJobQueue typOfJobQueue)
{
	int amount = 0;
	for (int i = 0; i < (*this->queue).size(); i++)
	{
		if ((*this->queue)[i].type == typOfJobQueue)
			amount =  (*this->queue)[i].queue.size();
	}

	return amount;
}






