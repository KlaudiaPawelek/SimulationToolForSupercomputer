#pragma once
#include "SimulationTool.h"
#include <vector>

using namespace std;

class InterfaceScheduler
{
public:
	vector<Job> *copy = new vector<Job>;
public:
	InterfaceScheduler();
	void CopyQueue( int amountOfUsers, int amountOfUsersPerGroup, int amountOfJobPerUser, Users *users);
	void DisplayQueue(int ampuntOfJob);
	void DisplayStatistics();
	~InterfaceScheduler();
};

