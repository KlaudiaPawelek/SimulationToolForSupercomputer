#include "pch.h"
#include "Users.h"

Users::Users()
{
}

Users::Users(int amount)
{
	this->course.resize(3);
	this->course[0] = Course(Course::ComputerMachineVision, amount);
	this->course[1] = Course(Course::ComputerAidedEngineering, amount);
	this->course[2] = Course(Course::SoftwareEngineering, amount);
}


Users::~Users()
{
}
