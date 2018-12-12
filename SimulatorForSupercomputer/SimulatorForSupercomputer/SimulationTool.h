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
extern int _CLOCK_;

class SimulationTool
{
public:
	ComputingSystem *system;
	Users *users;
	Scheduler *scheduler;
	multimap<Job, Nodes> *JobNodes = new multimap<Job,Nodes>;
public:
	SimulationTool();
	SimulationTool(int amountOfUsers, int budget);
	~SimulationTool();

	void RunScheduler();
	void MatchJobToResources();
	void ExecuteJobs();

	friend bool operator< (const Job &left, const Job &right);
	 void SetResourceTime(int time);
	vector<int> ExponentialDistributionEngine(int maxJobs, int maxNodes, int JobPerUser);
};
#endif

