#ifndef SIMULATIONTOOL_H
#define SIMULATIONTOOL_H

#pragma once
#include "ComputingSystem.h"
#include "Users.h"
#include "Scheduler.h"
#include <vector>
#include <map>
#include <iterator>
#include <cmath>

class SimulationTool
{
public:
	ComputingSystem *system;
	Users *users;
	Scheduler *scheduler;
	multimap<Job, Nodes> *JobNodes = new multimap<Job,Nodes>;
public:
	SimulationTool();
	SimulationTool(int amountOfUsers);
	~SimulationTool();

	void RunScheduler();
	void MatchJobToResources();
	void ExecuteJobs();

	friend bool operator< (const Job &left, const Job &right);
	vector<int> ExponentialDistributionEngine(int maxJobs, int maxNodes, int JobPerUser);
};
#endif

