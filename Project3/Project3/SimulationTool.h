#ifndef SIMULATIONTOOL_H
#define SIMULATIONTOOL_H

#pragma once
#include "ComputingSystem.h"
#include "Users.h"
#include "Scheduler.h"
#include "InterfaceScheduler.h"
#include <vector>
#include <map>
#include <iterator>
#include <cmath>
extern int _CLOCK_;
extern int _CLOCK2_;
extern int tmp;
extern int tmp2;

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
	void MatchJobToResources(int jobPerUser);
	void ExecuteJobs(int jobPerUser);

	friend bool operator< (const Job &left, const Job &right);
	vector<int> ExponentialDistributionEngine(int maxJobs, int maxNodes, int JobPerUser);
	void AddResourceTime(int jobID, int jobPerUser, int time);
	void AddExecuteTime(int jobID, int jobPerUser, int time);
};
#endif

