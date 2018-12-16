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

/**
	Global variable which simulates time.
	@see MatchJobToResources method
**/
extern int _CLOCK_;
/**
	Global variable which simulates time.
	@see ExecuteJobs method
**/
extern int _CLOCK2_;
/**
	Global variable which simulates time.
	@see MatchJobToResources method
**/
extern int tmp;
/**
	Global variable which simulates time.
	@see ExecuteJobs method
**/
extern int tmp2;

/**
	Simulation tool class is the main class in this program.
	It is repsonsible for simulation of entire environment.
	It is responsible for run the Scheduler also and match jobs to available resources.
	Additionally, in this class time is simulated.
	Simulation tool class is used only in main!
**/

class SimulationTool
{
public:
	/**
		Call ComputingSystem class.
		@see SimulationTool(int amountOfUsers, int budget)
	**/
	ComputingSystem *system;
	/**
		Call Users class.
		@see SimulationTool(int amountOfUsers, int budget)
	**/
	Users *users;
	/**
		Call Scheduler class.
		@see SimulationTool(int amountOfUsers, int budget)
	**/
	Scheduler *scheduler;
	/**
		Multimap for jobs and nodes.
	**/
	multimap<Job, Nodes> *JobNodes = new multimap<Job,Nodes>;
public:
	/**
		Default empty constructor
	**/
	SimulationTool();
	/**
		Constructor with parameters (parameters from main.cpp)
		@param int amountOfUsers
		@param int budget
	**/
	SimulationTool(int amountOfUsers, int budget);
	/**
		Default empty destructor.
	**/
	~SimulationTool();


	/**
		Run scheduler -> call GetNewJobs method from Scheduler class.
	**/
	void RunScheduler();

	/**
		SimulationTool can add to each job one node.
		Use in main file.
		@param int jobPerUser
		@return void
	**/
	void MatchJobToResources(int jobPerUser);

	/**
		Jobs are executed: it means that, flags like done, busy are updated.
		Jobs are deleted from queue.
		Use in main file.
		@param int jobPerUser
		@return void
	**/
	void ExecuteJobs(int jobPerUser);

	/**
		Add to each job time stamp - resource time.
		When did job get the node.
		Use in MatchJobToResources(int jobPerUser) method
		@param int jobID
		@param int jobPerUser
		@param int time
		@return void
	**/
	void AddResourceTime(int jobID, int jobPerUser, int time);

	/**
		Add to each job time stamp - execute time.
		When has been job done.
		Use in ExecuteJobs(int jobPerUser) method
		@param int jobID
		@param int jobPerUser
		@param int time
		@return void
	**/
	void AddExecuteTime(int jobID, int jobPerUser, int time);

	/**
		Overrided operator< for vector.
		@param const Job &left
		@param const Job &right
	**/
	friend bool operator< (const Job &left, const Job &right);

	/**
		Exponentail Distribution is using for create time attribute in Job object.
		Method is called in main, because it depends from intput parameters.
		@param int maxJobs
		@param int maxNodes
		@param int JobPerUser
		@return vector<int>
	**/
	vector<int> ExponentialDistributionEngine(int maxJobs, int maxNodes, int JobPerUser);

};
#endif

