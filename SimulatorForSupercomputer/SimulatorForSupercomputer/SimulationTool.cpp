#include "pch.h"
#include "SimulationTool.h"


SimulationTool::SimulationTool()
{

	this->system = new ComputingSystem();
	this->users = new Users();
	this->scheduler = new Scheduler();
}

SimulationTool::~SimulationTool()
{
}

void SimulationTool::RunScheduler()
{
	(*this->scheduler).GetNewJobs((*this->users));
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
				(*this->JobNodes).insert({(*queue)[i].queue[j] , (*nodes)[j]});
				(*nodes)[j].busy = true;
			}
				
		}
	}
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
				(*this->scheduler).DeleteJobFromQueue((*queue)[i],(*this->users));
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
