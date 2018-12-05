#ifndef SIMULATIONTOOL_H
#define SIMULATIONTOOL_H

#pragma once
#include "ComputingSystem.h"
#include "Users.h"
#include "Scheduler.h"

class SimulationTool
{
public:
	ComputingSystem system;
	Users users;
	Scheduler scheduler;
public:
	SimulationTool();
	~SimulationTool();

	void RunScheduler();
};
#endif

