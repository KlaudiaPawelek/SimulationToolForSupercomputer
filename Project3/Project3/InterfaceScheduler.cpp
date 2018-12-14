 #include "InterfaceScheduler.h"


InterfaceScheduler::InterfaceScheduler()
{
}

void InterfaceScheduler::CopyQueue(int amountOfUsers, int amountOfUsersPerGroup, int amountOfJobPerUser, Users *users)
{
	for (int i = 0; i < amountOfUsers / amountOfUsersPerGroup; i++)
	{
		for (int j = 0; j < amountOfUsersPerGroup; j++)
		{
			for (int k = 0; k < amountOfJobPerUser; k++)
			{
				(*this->copy).push_back((*users).course[i].student[j].GetJob(k));

			}
		}
	}
	sort((*this->copy).begin(), (*this->copy).end(), [](const Job& lhs, const Job& rhs)
	{
		return lhs.createTime < rhs.createTime;
	});
}

void InterfaceScheduler::DisplayQueue(int amountOfJob)
{
	//Simulation information
	cout << "--SIMULATION INFORMATION (time in imaginary time units)--\n";
	cout << "JOB_ID \t CREATE_TIME \t PUT_IN_QUEUE_TIME \t IN_QUEUE_TIME \t EXECUTION_TIME_STAMP \t RESOURCE_TIME_STAMP \n";
	for (int i = 0; i < amountOfJob; i++)
	{
		int inQueueTime = (*this->copy)[i].GetPutInQueueTime() + (*this->copy)[i].GetExecuteTime();
		(*this->copy)[i].SetInQueueTime(inQueueTime);
		cout << (*this->copy)[i].GetJobId() << " \t\t " << (*this->copy)[i].GetCreateTime() << " \t\t\t " << (*this->copy)[i].GetPutInQueueTime()
			<< " \t\t " << (*this->copy)[i].GetInQueueTime() << " \t\t " << (*this->copy)[i].GetExecuteTime() << " \t\t\t "
			<< (*this->copy)[i].GetResourceTime() << "\n";
	}

}

void InterfaceScheduler::DisplayStatistics()
{
	cout << "--STATISTICS-- \n";
	cout << "->Number of jobs processed in each queue (throughput) per week: \n";
	cout << "->Number of machine-hours consumed by user jobs: \n";
	cout << "->Utilization ratio: \n";
	cout << "->Resulting price paid by the users: \n";
	cout << "->Average wait time in each queue: \n";
	cout << "->Average turnaround time ratio: \n";
}


InterfaceScheduler::~InterfaceScheduler()
{
}
