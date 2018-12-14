 
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
	
	for (int i = 0; i < users.course.size(); i++) //3
	{
		for (int j = 0; j < users.course[i].student.size(); j++) //10
		{
			for (int k = 0; k < users.course[i].student[j].job->size(); k++) //2
			{
				//to fix!!!
				users.course[i].student[j].GetJob(k).SetJobInQueue(true);
				int delay = users.course[i].student[j].GetJob(k).GetCreateTime() + 1;
				users.course[i].student[j].GetJob(k).SetPutInQueueTime(delay);
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
		(*this->queue)[0].queue.push_back(job);

		//sort values using time variable
		sort((*this->queue)[0].queue.begin(), (*this->queue)[0].queue.end(), [](const Job& lhs, const Job& rhs)
		{
			return lhs.createTime < rhs.createTime;
		});
	}
}

int Scheduler::DeleteJobFromQueue(Queue &queue, Users &users)
{
	int id = queue.queue.front().GetJobId();
	queue.queue.erase(queue.queue.begin());
	return id;
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






