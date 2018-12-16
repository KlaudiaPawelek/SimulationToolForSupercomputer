#pragma once
#include "SimulationTool.h"
#include <vector>
#include <algorithm>

using namespace std;
/**
	InterfaceScheduler class is responsible for displaying information about Queue and about some statistics in the console.
	Displaying information has been separeted from main, important class SimulationTool.
	The most important method here is CopyQueue, which has access to important elements and then, they can be shown for user.
**/

class InterfaceScheduler
{
public:
	/**
		Vector of pointers to Job objects .
		Contain information from method CopyQueue.
	**/
	vector<Job> *copy = new vector<Job>;
public:
	/**
		Default, empty constructor.
	**/
	InterfaceScheduler();
	/**
		Method, which copy jobs from each student to one vector.
		Parameters are related to console parameters.
		@param int amountOfUsers - parameter from main file.
		@param int amountOfUsersPerGroup - parameter from main file.
		@param int amountOfJobPerUser - parameter from main file.
		@param Users *users - access to data, very important parameter.
	**/
	void CopyQueue( int amountOfUsers, int amountOfUsersPerGroup, int amountOfJobPerUser, Users *users);
	/**
		Method responsibles for displaying queue of job, after execute each job (not during the executing).
		Return information like jobID, create time, some time stamp etc.
		@param int amountOfJob - general number of job from each group, course, user.
		@return void
	**/
	void DisplayQueue(int ampuntOfJob);
	/**
		Method responsibles for displaying statistics described in User Requirements and Functional Requirements.
		@retrn void
	**/
	void DisplayStatistics(int amountOfJob, int budget);
	/**
		Default destructor.
	**/
	~InterfaceScheduler();
};

