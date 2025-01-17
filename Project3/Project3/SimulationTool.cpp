﻿ #include "SimulationTool.h"
int tmp = 0;	//initialize global variable
int tmp2 = 0;	//initialize global variable

// Default constructor
SimulationTool::SimulationTool()
{
}

// Constructor with parameters
SimulationTool::SimulationTool(int amountOfUsers, int budget)
{

	this->system = new ComputingSystem();
	this->users = new Users(amountOfUsers, budget);
	this->scheduler = new Scheduler();
}

// Default empty destructor
SimulationTool::~SimulationTool()
{
}

// Run scheduler
void SimulationTool::RunScheduler()
{
	(*this->scheduler).GetNewJobs((*this->users));
	vector<Queue> *queue = (*this->scheduler).GetQueue();
}

// Match jobs to resources
void SimulationTool::MatchJobToResources(int jobPerUser) //for small jobs
{
	vector<Nodes> *nodes = (*this->system).GetNodes(Nodes::traditional);
	vector<Queue> *queue = (*this->scheduler).GetQueue();
	
	int amountOfJob = (*this->scheduler).AmountOfJob(Queue::_short);
	for (int i = 0; i < (*queue).size(); i++)
	{
		if ((*queue)[i].type == Queue::_short)
		{
			if (amountOfJob < (*this->system).GetAmountOfNodes(Nodes::traditional))
			{
				_CLOCK_++;
				for (int j = 0; j < amountOfJob; j++)
				{
					(*queue)[i].queue[j].SetResourceTime(_CLOCK_);
					int jobID = (*queue)[i].queue[j].GetJobId();
					AddResourceTime(jobID, jobPerUser, _CLOCK_);
					(*nodes)[j].SetBusy(true);
					(*this->JobNodes).insert({ (*queue)[i].queue[j] , (*nodes)[j] });

					tmp++;

				}
			}
			else
			{
				_CLOCK_++;
				for (int j = 0; j < (*this->system).GetAmountOfNodes(Nodes::traditional); j++)
				{
					(*queue)[i].queue[j].SetResourceTime(_CLOCK_);
					int jobID = (*queue)[i].queue[j].GetJobId();
					AddResourceTime(jobID, jobPerUser, _CLOCK_);
					(*nodes)[j].SetBusy(true);
					(*this->JobNodes).insert({ (*queue)[i].queue[j] , (*nodes)[j] });

					tmp++;
					
				}
			}
			
		}
	}
}

// Execute jobs
void SimulationTool::ExecuteJobs(int jobPerUser)
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
				//---ISSUE HAS BEEN FOUND DURING THE TESTING!------

				//(*queue)[i].queue[tmp2].SetResourceTime(_CLOCK2_);
				//int jobID = (*queue)[i].queue[tmp2].GetJobId();
				//AddExecuteTime(jobID, jobPerUser, _CLOCK2_);
				//-------------------------------------------------

				int id = (*this->scheduler).DeleteJobFromQueue((*queue)[i], (*this->users));
				AddExecuteTime(id, jobPerUser, _CLOCK2_);
				(*nodes)[j].SetBusy(false);
				
				tmp2++;
			}
			
			_CLOCK2_++;
		}
	}
}

// Overridden operator< for vector
bool operator<(const Job & left, const Job & right)
{
	return left.jobID < right.jobID;
}

// Exponential distribution: exponential_distribution engine and default_random_engine are used!
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
		p_short[i-1]= (p[jobPerUser + 1-i] * maxNodes / maxJobs);
	}
	
	return p_short;
}

// Add resource time to each Student's Job object
void SimulationTool::AddResourceTime(int jobID, int jobPerUser, int time)
{
	int id = jobID;
	for (int i = 0; i < (*this->users).course.size(); i++)
	{
		for (int j = 0; j < (*this->users).course[i].GetNumberOfStudents(); j++)
		{
			for (int k = 0; k < jobPerUser; k++)
			{
				Job tmp = (*this->users).course[i].student[j].GetJob(k);
				int id2 = tmp.GetJobId();
				if (id == id2)
				{
					(*this->users).course[0].student[0].GetJob(0).SetResourceTime(time);
					break;
				}
			}
		}
	}
}

// Add execute time to each Student's Job object
void SimulationTool::AddExecuteTime(int jobID, int jobPerUser, int time)
{
	int id = jobID;
	for (int i = 0; i < (*this->users).course.size(); i++)
	{
		for (int j = 0; j < (*this->users).course[i].GetNumberOfStudents(); j++)
		{
			for (int k = 0; k < jobPerUser; k++)
			{
				Job tmp = (*this->users).course[i].student[j].GetJob(k);
				int id2 = tmp.GetJobId();
				if (id == id2)
				{
					(*this->users).course[i].student[j].GetJob(k).SetExecuteTime(time);
					(*this->users).course[i].student[j].GetJob(k).SetJobInQueue(false);
					(*this->users).course[i].student[j].GetJob(k).SetJobIsDone(true);
					break;
				}
			}
		}
	}
}
