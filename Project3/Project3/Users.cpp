 
#include "Users.h"

Users::Users()
{
}

Users::Users(int amount, int budget)
{
	this->course.resize(3);
	this->course[0] = Course(Course::ComputerMachineVision, amount, budget);
	this->course[1] = Course(Course::ComputerAidedEngineering, amount, budget);
	this->course[2] = Course(Course::SoftwareEngineering, amount, budget);
}


Users::~Users()
{
}
