#pragma once
#include "SimulationTool.h"
#include "InterfaceScheduler.h"
class Interface
{
public: 
	SimulationTool simulationTool;
	InterfaceScheduler interfaceScheduler;
public:
	Interface();
	~Interface();
};

