// SimulatorForSupercomputer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include <cstdio>	//for clock
//#include <ctime>	//for clock
#include <time.h>	//for clock variable?
#include "SimulationTool.h"

using namespace std;

/*void czekaj(int iMilisekundy)
{
	clock_t koniec = clock() + iMilisekundy * CLOCKS_PER_SEC / 1000.0;
	while (clock() < koniec) continue;

}

double obliczSekundy(clock_t czas)
{
	return static_cast <double>(czas) / CLOCKS_PER_SEC;
}*/

int main()
{
	//cout << "Simulation start." << obliczSekundy(clock()) << endl;

	//parameters from console, only for user->student
	int amountOfJob = 120;
	int amountOfJobPerUser = 4;		//per student
	int amountOfUsers = 30;			//students
	int amountOfUsersPerGroup = 10; // per course
	
	//create environment
	SimulationTool simulationTool(amountOfUsersPerGroup);
	int clock = 0;
	//each student creates job in "real-time"
	vector<int> delay;
	delay = simulationTool.ExponentialDistributionEngine(amountOfJob, 20, amountOfJobPerUser); //time from exponential... sec
	int tmp = 0;
	for (int i = 0; i < amountOfUsersPerGroup; i++)
	{
		
		simulationTool.users->course[0].student[i].CreateJob(2, delay[tmp]);
		clock = clock + delay[tmp];
		simulationTool.users->course[1].student[i].CreateJob(2, delay[tmp]);
		clock + delay[tmp];
		simulationTool.users->course[2].student[i].CreateJob(2, delay[tmp]);
		clock + delay[tmp];
		if (tmp < amountOfJobPerUser)
			tmp++;
		if(tmp == amountOfJobPerUser)
			tmp = 0;
	}
	
	//cout << "Zadania stworzone" << obliczSekundy(clock()) << endl;
	cout << "Zadania stworzone: " << clock << " jednostek czasu "<<endl;
	//jobs are in queue
 	simulationTool.RunScheduler();  //clock, jako zmienna globalna???

	//do something with jobs ;-)
	while (simulationTool.scheduler->AmountOfJob(Queue::_short) != 0)
	{
		simulationTool.MatchJobToResources();	//add to job resources
		simulationTool.ExecuteJobs();			//jobs are remove from queue and execute
	}
	cout << "End of simulation \n";
	
}


