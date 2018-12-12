#include "pch.h"
#include "SimulationTool.h"


SimulationTool::SimulationTool()
{
}

SimulationTool::SimulationTool(int amountOfUsers, int budget)
{

	this->system = new ComputingSystem();
	this->users = new Users(amountOfUsers, budget);
	this->scheduler = new Scheduler();
}

SimulationTool::~SimulationTool()
{
}

void SimulationTool::RunScheduler()
{
	(*this->scheduler).GetNewJobs((*this->users));
	vector<Queue> *queue = (*this->scheduler).GetQueue();
}

void SimulationTool::MatchJobToResources() //for small jobs
{
	vector<Nodes> *nodes = (*this->system).GetNodes(Nodes::traditional);
	vector<Queue> *queue = (*this->scheduler).GetQueue();

	int amountOfJob = (*this->scheduler).AmountOfJob(Queue::_short);
	for (int i = 0; i < (*queue).size(); i++)
	{
		if ((*queue)[i].type == Queue::_short)
		{
			for (int j = 0; j < (*this->system).GetAmountOfNodes(Nodes::traditional); j++)
			{
				_CLOCK_ ++;
				(*queue)[i].queue[j].SetResourceTime(_CLOCK_);
				SetResourceTime(_CLOCK_);
				(*this->JobNodes).insert({ (*queue)[i].queue[j] , (*nodes)[j] });
				(*nodes)[j].busy = true;
					
			}
		}
	}
	_CLOCK_++;
	
}

void SimulationTool::ExecuteJobs()
{
	vector<Nodes> *nodes = (*this->system).GetNodes(Nodes::traditional);
	vector<Queue> *queue = (*this->scheduler).GetQueue();

	int amountOfJob = (*this->scheduler).AmountOfJob(Queue::_short);
	for (int i = 0; i < (*queue).size(); i++)
	{
		if ((*queue)[i].type == Queue::_short)
		{

			for (int j = 0; j < (*this->system).GetAmountOfNodes(Nodes::traditional); j++)
			{
				
				(*this->scheduler).DeleteJobFromQueue((*queue)[i], (*this->users));
				(*nodes)[j].busy = false;
				// to do: change values in JobNodes multimap also ;-)
				
			}

		}
	}
}

bool operator<(const Job & left, const Job & right)
{
	return left.jobID < right.jobID;
}

void SimulationTool::SetResourceTime(int time)
{
	for (int i = 0; i <(*this->users).course.size(); i++)
	{
		for (int j = 0; j < (*this->users).course[i].student.size(); j++)
		{
			for (int k = 0; k < (*this->users).course[i].student[j].job->size(); k++)
			{

				(*this->users).course[i].student[j].GetJob(k).SetResourceTime(time);
			}
		}
	}
}

vector<int> SimulationTool::ExponentialDistributionEngine(int maxJobs, int maxNodes, int jobPerUser)
{
	default_random_engine generator;
	exponential_distribution<double> distribution(1.0);
	vector<double> p;
	vector<int> p_short;
	p.resize(maxJobs);
	p_short.resize(jobPerUser);

	for (int i = maxJobs - 1; i >=0; i--)
	{
		double number = distribution(generator);
		if (number < 1.0)
			++p[int(jobPerUser * number)];
	}
	
	for (int i = 1; i <jobPerUser+1; i++)
	{
		//cout<<(int)(p[i] * maxNodes / maxJobs);
		p_short[i-1]= (p[jobPerUser + 1-i] * maxNodes / maxJobs);
	}
	
	return p_short;
}
