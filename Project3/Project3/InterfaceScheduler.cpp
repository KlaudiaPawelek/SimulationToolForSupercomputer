 #include "InterfaceScheduler.h"

// Default, empty constructor.
InterfaceScheduler::InterfaceScheduler()
{
}

// Copy jobs from each student to one vector (copy).
void InterfaceScheduler::CopyQueue(int amountOfUsers, int amountOfUsersPerGroup, int amountOfJobPerUser, Users *users)
{

	for (int i = 0; i < amountOfUsers / amountOfUsersPerGroup; i++)
	{
		for (int j = 0; j < amountOfUsersPerGroup; j++)
		{
			for (int k = 0; k < amountOfJobPerUser; k++)
			{
				// put Job objects into vector
				(*this->copy).push_back((*users).course[i].student[j].GetJob(k));

			}
		}
	}

	// Sort jobs by create time - time, when job has been created by simulated user.
	sort((*this->copy).begin(), (*this->copy).end(), [](const Job& lhs, const Job& rhs)
	{
		return lhs.createTime < rhs.createTime;
	});
}

// Display queue after working of simulation tool.
void InterfaceScheduler::DisplayQueue(int amountOfJob)
{
	cout << "--SIMULATION INFORMATION (time in imaginary time units)--\n";
	cout << "JOB_ID \t CREATE_TIME \t PUT_IN_QUEUE_TIME \t IN_QUEUE_TIME \t EXECUTION_TIME_STAMP \n";

	for (int i = 0; i < amountOfJob; i++)
	{
		int inQueueTime = (*this->copy)[i].GetPutInQueueTime() + (*this->copy)[i].GetExecuteTime();
		(*this->copy)[i].SetInQueueTime(inQueueTime);
		cout << (*this->copy)[i].GetJobId() << " \t\t " << (*this->copy)[i].GetCreateTime() << " \t\t\t " << (*this->copy)[i].GetPutInQueueTime()
			<< " \t\t " << (*this->copy)[i].GetInQueueTime() << " \t\t " << (*this->copy)[i].GetExecuteTime() << " \t\t\t \n";
	}

}

// Display statistic described in User Requirements.
void InterfaceScheduler::DisplayStatistics(int amountOfJob, int budget)
{
	vector <float> timeTakenByEachJob;
	timeTakenByEachJob.resize(amountOfJob);
	vector <float> waitTimeVector;
	waitTimeVector.resize(amountOfJob);
	vector <float> executionTimeVec;
	executionTimeVec.resize(amountOfJob);
	float generalTime = 0.0;
	float waitTime = 0.0;
	float executionTime = 0.0;
	for (int i = 0; i < amountOfJob; i++)
	{
		timeTakenByEachJob[i] = (*this->copy)[i].GetExecuteTime() + (*this->copy)[i].GetInQueueTime() + (*this->copy)[i].GetResourceTime();
			generalTime = generalTime + timeTakenByEachJob[i];
		waitTimeVector[i] = (*this->copy)[i].GetInQueueTime();
			waitTime = waitTime + waitTimeVector[i];
		executionTimeVec[i] = (*this->copy)[i].GetExecuteTime();
			executionTime = executionTime + executionTimeVec[i];
	}
	// each information for small jobs
	static const float constantOperationalCostPerHour_Traditional = 0.01;
	static const float machineHourForSmallJobs = 0.1;
	float secondInFiveDays = 432000.0; //seconds from Monday to Friday (for small jobs)
	float secondInOneDay = 86400.0;
	float avgWaitTime = waitTime / amountOfJob;

	cout << "--STATISTICS-- \n";
	cout << "->General time taken by small jobs: " << generalTime << endl;
	cout << "->Number of small jobs processed in queue per week: "<< secondInFiveDays/generalTime <<endl;
	cout << "->Number of machine-hours consumed by user small jobs: " << secondInOneDay / generalTime << endl;
	cout << "->Utilization ratio for each student: " << ((secondInOneDay / generalTime) * constantOperationalCostPerHour_Traditional) / budget << endl;
	cout << "->Resulting price paid by the users: " << (secondInOneDay / generalTime) * constantOperationalCostPerHour_Traditional << endl;
	cout << "->Average wait time in queue: " << avgWaitTime << endl;
	cout << "->Average turnaround time ratio: " <<executionTime/amountOfJob <<endl;
}


// Default destructor.
InterfaceScheduler::~InterfaceScheduler()
{
}
