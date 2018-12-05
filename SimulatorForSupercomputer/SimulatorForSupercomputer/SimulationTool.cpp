#include "pch.h"
#include "SimulationTool.h"


SimulationTool::SimulationTool()
{
	ComputingSystem computingSystem;
	Users user;
	Scheduler scheduler;
}

SimulationTool::~SimulationTool()
{
}

void SimulationTool::RunScheduler()
{
	this->scheduler.GetNewJobs(this->users);
}
