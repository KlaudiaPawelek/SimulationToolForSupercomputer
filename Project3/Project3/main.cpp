// SimulatorForSupercomputer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>	//for parsing arguments from console
#include <string>		//for parsing arguments from console
#include "SimulationTool.h"

int _CLOCK_ = 0;	//simulated time
int _CLOCK2_ = 0;	//simulated time
using namespace std;

int main(int argc, char* argv[])
{

	//parameters important for simulation
	int amountOfJob = 0;			//general amount of jobs
	int amountOfJobPerUser = 0;		//jobs per student
	int amountOfUsers = 0;			//amount of students
	int amountOfUsersPerGroup = 0;	//amount of studented per course - three different options
	int budget = 0;					//general budget

	//parsing arguments from console
	string arg;
	string arg2;
	string arg3;
	string arg4;
	string arg5;
	try
	{
		arg = argv[1];
		arg2 = argv[2];
		arg3 = argv[3];
		arg4 = argv[4];
		arg5 = argv[5];
		size_t position;
		amountOfJob = stoi(arg, &position);
		amountOfJobPerUser = stoi(arg2, &position);
		amountOfUsers = stoi(arg3, &position);
		amountOfUsersPerGroup = stoi(arg4, &position);
		budget = stoi(arg5, &position);
	}
	catch (invalid_argument const &exception)
	{
		cerr << "Invalid argument: " << arg << '\n';
	}

	try
	{
		if (argc < 6 || amountOfJob<=0 || amountOfJobPerUser<=0 || amountOfUsers<=0 || amountOfUsersPerGroup <= 0 )
		{
			cout << "Insert 5 arguments: amount of jobs, amount of job per user, amount of users, amount of users per group, budget \n";
			cout << "Values have to be grater than 0!";
			exit(0);
		}
		else if (argc == 6 && (amountOfJob>0 && amountOfJobPerUser>0 && amountOfUsers>0 && amountOfUsersPerGroup>0))
		{
			//create environment: computing system, useres, scheduler
			SimulationTool simulationTool(amountOfUsersPerGroup, budget);

			//each student creates job in different time; delay contains 'time units' described by exponential distribution
			vector<int> delay;
			delay = simulationTool.ExponentialDistributionEngine(amountOfJob, simulationTool.system->GetAmountOfNodes(Nodes::traditional), amountOfJobPerUser);
			for (int i = 0; i < amountOfUsersPerGroup; i++)
			{
				simulationTool.users->course[0].student[i].CreateJob(amountOfJobPerUser, delay);
				simulationTool.users->course[1].student[i].CreateJob(amountOfJobPerUser, delay);
				simulationTool.users->course[2].student[i].CreateJob(amountOfJobPerUser, delay);
			}

			//jobs are in queue
			simulationTool.RunScheduler();

			//add resources to each job, then each job leaves queue and then it is executed
			while (simulationTool.scheduler->AmountOfJob(Queue::_short) != 0)
			{
				//add to resources to each job
				simulationTool.MatchJobToResources(amountOfJobPerUser);

				//jobs are remove from queue and execute
				simulationTool.ExecuteJobs(amountOfJobPerUser);
			}

			//display information about queue and some statistics
			InterfaceScheduler interfaceScheduler;
			interfaceScheduler.CopyQueue(amountOfUsers, amountOfUsersPerGroup, amountOfJobPerUser, simulationTool.users);
			interfaceScheduler.DisplayQueue(amountOfJob);
			interfaceScheduler.DisplayStatistics(amountOfJob, budget);

			cout << "\n--End of simulation--";
		}
	}
	catch (const exception& exception)
	{
		cout << "--Something went wrong! \n";
		cerr << "--Exception has been caught. \n";
		cerr << "--Type: " << typeid(exception).name() << "\n";
		cerr << "--Additional information: " << exception.what() << "\n";
	}

}


