// SimulatorForSupercomputer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "SimulationTool.h"

using namespace std;

int main()
{
    cout << "Klaudia - supercomputer! \n"; 
	SimulationTool simulationTool;
 	simulationTool.RunScheduler();
	while (simulationTool.scheduler->AmountOfJob(Queue::_short) != 0)
	{
		simulationTool.MatchJobToResources();
		simulationTool.ExecuteJobs();
	}
	cout << "Thank you \n";
	

}


